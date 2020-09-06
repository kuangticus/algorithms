/*******************************************************************************
 ** changeTime.cpp
 ** WeiHao Kuang
 ** 07/11/2018
 ** Minimum change maker algorithm, finds exact change, and times it
 ** internal input
 ** Output file "changeTime.txt"
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
#include<ctime>

using namespace std;

long int min_change (vector<long int>, long int, long int);
/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main () {
    // These are variable intializations
    ofstream write_file; // write to file
    vector<long int> holder; // makes a long int vector to hold ints from read
    long int amount = 0, increase = 0; // used for loop conditions
    clock_t start, stop;

    srand(time(NULL));

    // opens a file named "change.txt" store the sorted array values
    write_file.open("changeTime.txt");
    // while loop runs for the until increase is 8000
    while ( increase != 8000 ){
        increase = increase + 400; // increases 400 every iteration
        //for ( int i = 0; i < increase; i++){
        for ( int i = 0; i < 4000; i++){
            holder.push_back(  rand()%200 ); // push numbers to the vector
        }
        //amount =  8000; // the A value increase be 2500 every iter
        amount =  increase + 100; // the A value increase be 2500 every iter
        // beginning the timing sequence
        // Once the stop variable recieve clock() the timing is over
        start = clock();
          cout << "Minimum Coins: "
               << min_change ( holder, holder.size(), amount) << endl;
        stop = clock();
        // Calculating the time while simultaneously writing to the external
        // where things are stored
        /*write_file << increase << ' ' <<((stop - start) / (CLOCKS_PER_SEC / 1000))
                     << endl;*/
        write_file << amount << ' ' <<((stop - start) / (CLOCKS_PER_SEC / 1000))
                   << endl;

        holder.clear(); // flushes the vector for next use
    }

    return 0;
}
/*******************************************************************************
** Function: change_maker
** Description: finds minimum change for wanted value
** Parameters: vector<int>, size, amount
** Pre-Conditions: vector will be used to find minimum change
** Post-Conditions: return long int, minimum coins used
*******************************************************************************/
long int min_change(vector<long int> coin_denom, long int size_coins,
                    long int change_amount){

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
  		  cout << 0 << endl;
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
  	}
  	return min_table[change_amount]; // returns the min coins used
}
