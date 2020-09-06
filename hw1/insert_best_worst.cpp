/**************************************************************************************************
 ** insert_best_worst.cpp 
 ** WeiHao Kuang
 ** 06/28/2018
 ** Insertion sort algorithm run time calculation for best and worst cases
 ** There is not external input, the arrays are filled internally via random # generator
 ** Output file "insert_best_worst.txt"
**************************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

void insertion_sort(int*, int); 
void timer(int*, int, int*);

/**************************************************************************************************
** Function: main
** Description: using the insertion algoritm sorts int array (ascending)
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
**************************************************************************************************/ 
int main () {
    clock_t start, stop;
    int average = 0;
    int *array = new int[50000]; // dynamic array

    // best case generation, where the numbers are already ordered when the array is fill
    // runs three trials and gets the average complextiy is n
    cout <<  right << setw(12) << "Best Case:  " ;
    for ( int j = 0; j  < 3; j++ ) { // 3 iterations to get average
        for (int i = 0; i < 50000; i++){ //=fills the array from 0 -> 90000 in ascending order  
            array[i] = i + j; // I add j everytime to create trial variation (still ascending order)
        }
        timer (array, 50000, &average); // calling the timing funciton
    }
    cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console
    
    average = 0; // average resets to zero everytime time 3 trials of the same n run thru

    /// worst case generation, where the numbers are order in decending order when the array is fill
    // runs three trials and gets the average  complexity in n^2
    cout << right << setw(1) << "Worst Case:  " ;
    for ( int j = 0; j  < 3; j++ ) { // 3 trials to get an average, hence 3 iterations
        for (int i = 0; i < 50000; i++){ // fills array array from 90000 -> 0 
            array[i] = 50000 - i; // I subtract j everytime to create variation every trial(still descending order)
        }
        timer (array, 50000,  &average); // calls the timing funciton
    }
    cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console
  
        /* NOTE!!: The outputted table on both the console and the .out file is in this following format:

        | case type | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | average time (mS)|
        
        this format will be consitent for n size ranging from 5000 - 70000 by increments of 5000. 
        */
  
    delete array; // frees the dynamic memory
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
** Parameters: int unsort pointer (array) and average, int array_size,
** Pre-Conditions: Must have a valid array passed int, and a non-neg int, and availble file name
** Post-Conditions: there will there will be the run time and averages posted
*************************************************************************************************/ 
void timer (int *array, int array_size, int *average){

    clock_t start, stop; // creates two clock type varibles start and stop
    start = clock(); // assgining clock to start
        insertion_sort (array, array_size); // insertion sort called 
    stop = clock(); // assigning end clock to stop
  
    *average += ((stop - start) / (CLOCKS_PER_SEC / 1000)); // addes a running value for time 3 trials
    cout<< left << setw(5) << ((stop - start) / (CLOCKS_PER_SEC / 1000)) << " "; // outputs the timing to console (mS)
  
} 
