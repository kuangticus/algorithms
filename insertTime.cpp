/**************************************************************************************************
 ** insertTime.cpp 
 ** WeiHao Kuang
 ** 06/28/2018
 ** Insertion sort algorithm run time calculation
 ** There is not external input, the arrays are filled internally via random # generator
 ** Output file "insertTime.out"
**************************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
#include<iomanip>


using namespace std;
using ms = chrono::milliseconds;

void insertion_sort(int*, int); 
void timer(int*, int, ofstream&, int*);

/**************************************************************************************************
** Function: main
** Description: using the insertion algoritm sorts int array (ascending)
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
**************************************************************************************************/ 
int main () {
    int array_size = 14; // 5000 - 70000; by increments of 5000
    int size = 0, average = 0;
    ofstream insertTime; // creates an object insertTime for output file

    insertTime.open("insertTime.out"); // creates a text file to store the runtimes and averages to make a table
    srand (time(NULL)); // seeds the rand function generator 

    for (int i = 0; i < array_size; i++){ // this for loop is looping through the 14 differne sample sizes
      
        size = size + 5000; //increments 5000 every iteration from 0 -> 70000
        int array[size]; // temp array used for storing the randomly generated data
        insertTime << size << " "; // used to write n size to external file
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
            timer (array, size, insertTime, &average);
        }
        

        cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console
        insertTime << (float)average/3 << endl; // aveage times of 3 trials, outputted to external table
        average = 0; // average resets to zero everytime time 3 trials of the same n run thru

        /* NOTE!!: The outputted table on both the console and the .out file is in this following format:

        | n size | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | average time (mS)|
        
        this format will be consitent for n size ranging from 5000 - 70000 by increments of 5000. 
        */

    }
    return 0;
}
/*************************************************************************************************
** Function: insetion_sort
** Description: using the insertion algoritm sorts int array (ascending)
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
*************************************************************************************************/ 
void insertion_sort( int *unsorted, int array_size){
    int key = 0, j = 0; 

    for (int i = 1; i < array_size ; i++) { // for loop runs based on array size
        key = unsorted[i]; // key gets the int that is to be sorted in array 
        j = i-1;  // this is used to look back at previous indexes 

        // condtion for while loop is that if j does not signfy the end of the array, and the if 
        // key(to be sorted value) is less than its neighbor to the left it will swap places 
        // swaps until key is greater than its left neighbor. 
        while (j >= 0 && unsorted[j] > key) {
            unsorted[j+1] = unsorted[j]; // left neighbor and right neighbor swap because key < left neighbor (left neighbor >= 0)
            j = j-1;
        }
       unsorted[j+1] = key; // getting place in the correct place.
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

    //this section is the timer block that times the insertion sort algorithm
    //the time unit is in milliseconds
    auto start = chrono::steady_clock::now(); // start the clock timing
        insertion_sort (array, array_size); // insertion sort call
    auto end = chrono::steady_clock::now(); // ends the clock timing
    auto diff = end - start; // final minus the intial will give the actually time ran.

    // this add the time values together, this recreate a running total, and 
    // in main this number is divided by 3, to get runtime average of 3 trials of the same n size
    *average += chrono::duration_cast<ms>(diff).count(); 
    cout<< left << setw(5) << chrono::duration_cast<ms>(diff).count() << " "; // outputs the timing to console (mS)
    file << chrono::duration_cast<ms>(diff).count() << " "; // outputs the timing numbers to out file (mS)
} 
