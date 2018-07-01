/***********************************************************************************
 ** merge_best_worst.cpp 
 ** WeiHao Kuang
 ** 06/28/2018
 ** Merge sort algorithm run time calculation, for best and worth case 
 ** Internal input from random number generator
 ** Output file "merge_best_worst.txt"
 ** Citation:https://www.geeksforgeeks.org/merge-sort/ :used as reference
***************************************************************************************/
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;


void timer(int*, int, int*);
void merge_sort(int*, int, int);
void merge(int*, int);

int main () {
     int *array = new int[1000000]; // dynamic array
    int average = 0;

    // best case generation, where the numbers are already ordered when the array is fill
    // runs three trials and gets the average  complexity n log n
    cout <<  right << setw(13) << "Best Case:  " ;
    for ( int j = 0; j  < 3; j++ ) { // 3 iterations to get average
        for (int i = 0; i < 1000000; i++){ //=fills the array from 0 -> 90000 in ascending order  
            array[i] = i + j; // I add j everytime to create trial variation (still ascending order)
        }
        timer (array, 1000000, &average); // calling the timing funciton
    }
    cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console
    
    average = 0; // average resets to zero everytime time 3 trials of the same n run thru

    // worst case generation, where the maximum comparsion are present, every half array need to be
    // compared, so but the complexity is still n log n
    cout <<  right << setw(2) << "Worst Case:  " ;
    for ( int j = 0; j  < 3; j++ ) { // 3 iterations to get average
        for (int i = 0; i < 1000000; i++){ //cycles 1 mil times to assign evens to left array, and odds to right array 
            if ( i <= 499999 ) {
                if ( i % 2 == 0 ) // looks of even i's
                    array[i] = i + (j*2) ; // fills the left half with evens, (j*2) is for trial variation
            }
            else{ 
                if ( i % 2 != 0) // looks for odd i's
                    array[i] = i + (j*2) ; // fills the right half with odds, (j*2) is for trial variation
            }
        }
        timer (array, 1000000, &average); // calling the timing funciton
    }
    cout << (float)average/3 <<endl; // average times of 3 trials, outputed to the console

        /* NOTE!!: The outputted table on both the console and the .out file is in this following format:

        | case type | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | average time (mS)|
        
        this format will be consitent for n size ranging from 5000 - 70000 by increments of 5000. 
        */
    //}
    delete [] array;
    return 0;
}
/************************************************************************************************************
** Function: timer 
** Description: times the merge sort algo. time is in milliseconds
** Parameters: int unsort pointer (array) and average, int array_size, ofstream file 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int, and availble file name
** Post-Conditions: there will there will be the run time and averages posted
******************************************************************************************************************/ 
void timer (int *array, int array_size, int *average){
    clock_t start, stop; // creates the clock objects
    start = clock(); // start clock
        merge_sort (array, 0, array_size - 1); //calls merge sort to time
    stop = clock(); // end clock 

    *average += (stop - start) / (CLOCKS_PER_SEC / 1000); // this will keep a total of the time for every trial (used for average)
    cout<< left << setw(5) << (stop - start) / (CLOCKS_PER_SEC / 1000) << " "; // outputs the timing to console (mS)
} 
/***************************************************************************************************************
** Function: merge
** Description: merges 2 sub arrays into one
** Parameters: array pointer, int left, middle and right
** Pre-Conditions: must be a valid array pointer, right ints passed in
** Post-Conditions: the inputted array will be ordered
****************************************************************************************************************/ 
void merge(int *array, int left, int middle, int right)
{
    int i, j, k;
    int place1 = middle - left + 1;
    int place2 =  right - middle;
    int left_array[place1], right_array[place2]; //temp left and right arrays that will store the input array data
 
    
    for (i = 0; i < place1; i++) // copies the array input left side into leftside temp array, using for loop
        left_array[i] = array[left + i];

    for (j = 0; j < place2; j++)// copies the array input right side into leftside temp array, using for loop
        right_array[j] = array[middle + 1 + j];
 
    i = 0; // intial subarray index (1st sub array) 
    j = 0; // initial subarray index (2nd sub array)
    k = left; // merged subarray index, changes based on whether the array is part of the left subtrees or right subtrees

    while (i < place1 && j < place2) { // the condition for looping is that so long as the arrays (1 & 2) are not at its end the loop run
        
        // the first is used to sort all of the smaller numbers of the left_array first
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i]; // assigning the merged array a number at k
            i++; // increment i to test for the next number
        }
        else // else statment is for when the left_array has a number bigger than the right_array
        {
            array[k] = right_array[j]; //assigns array[k] the smaller number 
            j++; // increments so that the first condition can be tested
        }
        k++; // k increment regardless of which conditional statement executes
    }
 
    while (i < place1) { // this while copies any remaining ints left in left_array over to the merged array
        array[k] = left_array[i];
        i++; // increments i until the size of the array - 1 is reached
        k++; // k is incremented to move down the array for every int added to the array
    }
 
    while (j < place2) { // this while copies any remaining ints left in right_array over to the merged array
        array[k] = right_array[j];
        j++; // increments i until the size of the array - 1 is reached
        k++; // k is increment to make to move down the array for every int added to the array
    }
}
 /********************************************************************************************************************
** Function: merge_sort
** Description: sorts the array passed in using merger sort algo
** Parameters: array pointer, int left and right
** Pre-Conditions: must be a valid array
** Post-Conditions: passed in array is sorted
************************************************************************************************************************/ 
void merge_sort(int *array, int left, int right){
    
    if (left < right) { //condition for 
        
        //divid and conquere characteristis here.
        int middle = left+(right-left)/2; // searchs for the half point of the passed in array

        merge_sort(array, left, middle); //recursvily sorts left half
        merge_sort(array, middle + 1, right); //recusily sorts right half
        merge(array, left, middle, right); // the merge function is called put everything together once the recursion breaks
    }
}
