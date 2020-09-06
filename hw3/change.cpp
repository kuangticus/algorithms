/*******************************************************************************
 ** change.cpp
 ** WeiHao Kuang
 ** 07/11/2018
 ** Minimum change maker algorithm, finds exact change
 ** Input file "amount.txt"
 ** Output file "change.txt"
 ** Citiation: used as reference (below)
 ** https://www.geeksforgeeks.org/find-minimum-number-of-denom-that-make-a-change/
 ** http://www.cse.iitd.ac.in/~rjaiswal/2016/col351/Homework/hw-04-soln.pdf
*******************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>

using namespace std;

long int min_change (vector<long int>, long int, long int, ofstream& );

/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main () {
    // These are variable intializations
    ifstream read_file; // read from file
    ofstream write_file; // write to file
    string line, line2; // lines to read from file
    vector<long int> holder; // makes a int vector to hold ints from read
    long int number, amount; // used for loop conditions


    // opens a file named "data.txt" to read values from.
    read_file.open("amount.txt");
    // opens a file named "change.txt" store the sorted array values
    write_file.open("change.txt");

    if(read_file.good()){ // checks the file opened, returns true or false

      //this while loop takes care of the read and writing to the files
      //also within this for loop the timing funciton is called.
      while ( !read_file.eof() ){
          // gets the even line denoting the denomination
          getline( read_file, line );
          istringstream stuff( line ); // uses a stream to puts string into ints
          while ( stuff >> number ) {
              holder.push_back( number ); // push numbers to the vector
          }
          // this for loop write the denomination from the read file to the
          //external file called change.txt
          for ( int i = 0; i <holder.size(); i++ ) {
              write_file << holder[i] << " ";
          }
          write_file << endl; // new line and stream flush
          // gets the old lines where that denote the value of change that is
          // is need in change
          getline( read_file, line2 );
          istringstream stuff2(line2); // stream to change string to ints
          while ( stuff2 >> amount ) {
                write_file << amount << endl; // writes to the external file
          }
          // calls the min_change function to calculation the minimum number of
          // coins needed for an amount
          write_file << min_change(holder, holder.size(), amount, write_file)
                     << endl;
          holder.clear(); // flushes the vector reintialiizing it
      }
    }
    return 0;
}
/*******************************************************************************
** Function: change_maker
** Description: finds minimum change for wanted value
** Parameters: vector<int>, size, amount, write_file external output
** Pre-Conditions: vector will be used to find minimum change
** Post-Conditions: return long int, minimum coins used
*******************************************************************************/
long int min_change(vector<long int> coin_denom, long int size_coins,
                    long int change_amount, ofstream& write_file){

    // the following two arrays are used to one calculate the min coins
    // the other one is used to store the coins that where used
  	long int min_table[change_amount + 1]; // used for mini coin calc.
  	long int used_table[change_amount + 1]; // used for coins used

    //base case of search, for minimum coins
  	min_table[0] = 0;

    //for loop is used here to make all of the values from used_table
    // infinite
  	for (int i = 1; i <= change_amount ; i++) {
    		min_table[i] = INT_MAX; // INT_MAX essentially makes the value infinity
    		used_table[i]= -1; // initializises the coins used processes
  	}

    // first for loop is used to step through the temp array and fill the
    // array with the answers to sub problems, also determines the minimum
    //coins needed
  	for (int i = 1; i <= change_amount; i++) {
    		for (int j = 0; j < size_coins; j++)
        		if (coin_denom[j] <= i) { // check the coin values smaller than i
        			if ( min_table[i] > 1 + min_table[i-coin_denom[j]] ) {
          				min_table[i] = 1 + min_table[i-coin_denom[j]];
                  // this finds the minimum coins used for the value i
                  // up until the change_amount desirec
          				used_table[i] = j;
        			}
        		}
  	}
    // this conditional is used to check if there are coin matches for
    // change amount such that if the last value of the used-array is zero
    // there will be no change made since none is available
  	if ( used_table[change_amount ] == -1 ) {
  		  write_file << 0 << endl;
  	}
    // this conditional is used when there is change and the contents inside
    // find the coins that were used to find the minimum change for change_amount
  	else {
    		int start = change_amount ; // start off with the correct value
    		int array[size_coins]; // makes a temp array that is as large as coins
        // runs the loop to intialize all values in the array
        for(int a = 0; a < size_coins; a++) {
  			     array[a] = 0; // intialize to zero
  		  }
        // loop is used to check for the coin that are used to make the coins
        // change, this time it will loop through the coin array to increment
        // to the correct usage of the coin to make change.
    		while(start != 0) { // loop run if the start is not 0
      			int j = used_table[start];
      			array[j]++; // increments the index value
      			start = start - coin_denom[j];
  		  }
        // this for loop is used to output the array to the external file
  		  for(int a = 0; a < size_coins; a++) {
  			    write_file << array[a] << " ";
  		  }
  		  write_file << endl;
  	}
  	return min_table[change_amount]; // returns the min coins used
}
