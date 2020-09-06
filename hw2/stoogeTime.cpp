/**************************************************************************************************
 ** stoogeTime.cpp 
 ** WeiHao Kuang
 ** 07/3/2018
 ** Stooge sort algorithm run time calculation
 ** There is not external input, the arrays are filled internally via random # generator
 ** Output file "stoogeTime.txt"
 ** Citation: https://www.geeksforgeeks.org/stooge-sort/ // used for reference
**************************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<cmath>

using namespace std;

void stooge_sort(int*, int, int); 
void timer(int*, int, ofstream&, int*);

/*********************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*********************************************************************/  
int main () {
    int array_size = 15; // 5000 - 70000; by increments of 5000
    int size = 0, average = 0;
    ofstream stoogeTime; // creates an object stoogeTime for output file

    stoogeTime.open("stoogeTime.txt"); // creates a text file to store the runtimes and averages to make a table
    srand (time(NULL)); // seeds the rand function generator 

    for (int i = 0; i < array_size; i++){ // this for loop is looping through the 14 differne sample sizes
      
        size = size + 500; //increments 5000 every iteration from 0 -> 70000
        int array[size]; // temp array used for storing the randomly generated data
        stoogeTime << size << " "; // used to write n size to external file
        cout<< "n=" <<right << setw(5) << size << "  "; // used to write n size to the terminal

        // loops three times to generate 3 diff results for same n value
        // and then an average is taken to be used for graphing
        for ( int a = 0; a < 3; a++ ) { 
            for ( int j = 0; j < size; j++ ){
                array[j] = rand()%10000;
            }
            // calls the timer function which is responisble for 
            // time how long the algorithm runs
            // timing values are in milliseconds
            timer (array, size, stoogeTime, &average);
        }
        

        cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console
        stoogeTime << (float)average/3 << endl; // aveage times of 3 trials, outputted to external table
        average = 0; // average resets to zero everytime time 3 trials of the same n run thru

        /* NOTE!!: The outputted table on both the console and the .out file is in this following format:

        | n size | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | average time (mS)|
        
        this format will be consitent for n size ranging from 500 - 7500 by increments of 500. 
        */

    }
    return 0;
}
/*************************************************************************************************
** Function: stooge_sort
** Description: using the stooge sort algoritm sorts int array (ascending)
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
*************************************************************************************************/ 
 void stooge_sort(int *array, int top, int bottom) {

    int index;
 
    // this condition swaps the values of the first and last values if the value are: a[0] > a[1]
    if ( array[top] > array[bottom]) 
        swap(array[top], array[bottom]);


    if (bottom - top + 1 > 2) { // this activate is the array is more than 2 ints big
    
        // rounds the number up so that the there can be the right amount of recursive calls are made
        index = ceil((bottom - top + 1) / 3); 
        stooge_sort(array, top, bottom - index); // recursive call to sort first 2/3 of the array
        stooge_sort(array, top + index, bottom); // recursive call to sort second 2/3 of array 
        stooge_sort(array, top, bottom - index); // checks the first 2/3 and sorts againg for verify.
    }
}
/************************************************************************************************
** Function: timer 
** Description: times the insertion sort algo. , time is in milliseconds
** Parameters: int unsort pointer (array) and average, int array_size, ofstream file 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int, and availble file name
** Post-Conditions: there will there will be the run time and averages posted
*************************************************************************************************/ 
void timer (int *array, int array_size, ofstream &file, int *average){

    clock_t start, stop; // creates two clock type varibles start and stop
    start = clock(); // assgining clock to start
        stooge_sort (array, 0, array_size); // insertion sort called 
    stop = clock(); // assigning end clock to stop
  
    *average += ((stop - start) / (CLOCKS_PER_SEC / 1000)); // addes a running value for time 3 trials
    cout<< left << setw(5) << ((stop - start) / (CLOCKS_PER_SEC / 1000)) << " "; // outputs the timing to console (mS)
    file << ((stop - start) / (CLOCKS_PER_SEC / 1000)) << " "; // outputs the timing numbers to out file (mS)*/
} 
