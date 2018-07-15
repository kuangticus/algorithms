/*******************************************************************************
 ** change.cpp
 ** WeiHao Kuang
 ** 07/11/2018
 ** Minimum change maker algorithm, finds exact change
 ** Input file "data.txt"
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

int* change_maker (vector<int>, int, int);


int main () {
    // These are variable intializations
    ifstream read_file; // read from file
    ofstream write_file; // write to file
    string line, line2; // lines to read from file
    vector<int> holder; // makes a int vector to hold ints from read
    int number, amount; // used for loop conditions
    int *array; // used to carry hold a dynamic array

    // opens a file named "data.txt" to read values from.
    read_file.open("data.txt");
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
          // array holds the dynamic return of the change maker
          array = change_maker(holder, holder.size(), amount);
          write_file << array[amount] << endl;
          holder.clear(); // flushes the vector reintialiizing it
          delete [] array; //free dynamic memmory

      }
    }

    return 0;
}

int* change_maker(vector<int> denom, int size, int amount){
    //makes a temp array to hold sub problem solutions
    int *table = new int[amount+1];

    table[0] = 0; // base case

    // initialiaziontion of all the array parts to be max int
    for (int i=1; i<=amount; i++)
        table[i] = INT_MAX;

    // first for loop is used to step through the temp array and fill the
    // array with the answers to sub problems, also determines the minimum
    //coins needed
    for (int i=1; i<=amount; i++) {

        //second for loop is used to step through the the coins array to find
        // most optimal combination for the change making
        for (int j=0; j<size; j++)
            //checks the ammount and the coin to see eqvialences
            // if statment deals with i values less than amount
            if (denom[j] <= i && i != amount ) {
                int compare = table[i-denom[j]];
                if (compare != INT_MAX && compare + 1 < table[i])
                    // assignment statement responsible for finding the
                    // minimum coin assignment to table array
                    table[i] = compare + 1;
            }
            // conditional deals with the i value that is equal to amount
            else {
                int compare = table[i-denom[j]];
                if (compare != INT_MAX && compare + 1 < table[i])
                    // assignment statement responsible for finding the
                    // minimum coin assignment to table array
                    table[i] = compare + 1; //
            }

    }
    return table;
}
