/*******************************************************************************
 ** changeTime.cpp
 ** WeiHao Kuang
 ** 07/11/2018
 ** Minimum change maker algorithm, finds exact change
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

long int change_maker (vector<long int>, long int, long int);


int main () {
    // These are variable intializations
    ifstream read_file; // read from file
    ofstream write_file; // write to file
    string line, line2; // lines to read from file
    vector<long int> holder; // makes a long int vector to hold ints from read
    long int number, amount, increase = 1000; // used for loop conditions
    long int *array; // used to carry hold a dynamic array
    clock_t start, stop;

    srand(time(NULL));

    // opens a file named "change.txt" store the sorted array values
    write_file.open("changeTime.txt");

    while ( increase != 10000 ){
        increase += 500;
        for ( long int i = 0; i < increase; i++){
            holder.push_back( i ); // push numbers to the vector
        }
        amount = rand()%12000;
        start = clock();
          cout << "Minimum Coins: " << change_maker ( holder, holder.size(), amount) << endl;
        stop = clock();
        write_file << ((stop - start) / (CLOCKS_PER_SEC / 1000)) << " " << amount << " " << increase << endl;

        holder.clear();
    }

    return 0;
}

long int change_maker(vector<long int> denom, long int size, long int amount){
    //makes a temp array to hold sub problem solutions
    long int *table = new long int[amount+1];

    table[0] = 0; // base case

    // initialiaziontion of all the array parts to be max long int
    for (long int i=1; i<=amount; i++)
        table[i] = INT_MAX;

    // first for loop is used to step through the temp array and fill the
    // array with the answers to sub problems, also determines the minimum
    //coins needed
    for (long int i=1; i<=amount; i++) {

        //second for loop is used to step through the the coins array to find
        // most optimal combination for the change making
        for (long int j=0; j<size; j++)
            //checks the ammount and the coin to see eqvialences
            // if statment deals with i values less than amount
            if (denom[j] <= i && i != amount ) {
                long int compare = table[i-denom[j]];
                if (compare != INT_MAX && compare + 1 < table[i])
                    // assignment statement responsible for finding the
                    // minimum coin assignment to table array
                    table[i] = compare + 1;
            }
            // conditional deals with the i value that is equal to amount
            else {
                long int compare = table[i-denom[j]];
                if (compare != INT_MAX && compare + 1 < table[i])
                    // assignment statement responsible for finding the
                    // minimum coin assignment to table array
                    table[i] = compare + 1; //
            }

    }
    return table[amount];
}
