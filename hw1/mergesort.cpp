/***************************************************************************************
 ** mergesort.cpp 
 ** WeiHao Kuang
 ** 06/28/2018
 ** Merge sort algorithm with input and out file streams
 ** Input file "data.txt"
 ** Output file "merge.out"
 ** Citation:https://www.geeksforgeeks.org/merge-sort/: used as reference
***************************************************************************************/
#include<iostream>
#include<fstream>

using namespace std;
void merge_sort(int*, int, int);
void merge(int*, int);
void print_array (int*, ofstream&, int); 

/*********************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*********************************************************************/ 
int main () {
    ifstream read_file;
    ofstream sorted;
    int array_size = 0;

    read_file.open("data.txt"); // opens a file named "data.txt" to read from
    sorted.open("merge.out"); // opens a file named "merge.out" to write the output to

    if(read_file.good()){ // checks to see if the file fstream object "read_file" is open and exists: returns 1 or 0

        while (!read_file.eof()) { // loop condition is not at the end it reads, else it stops

            read_file >> array_size; // this reads the first int that is used to determine the size of the array. 
            int array[array_size]; // temp array for the ints read line by line
            // for loop that fills the temp array up from one line of int from "data.txt"
                for (int i = 0; i < array_size; i++){
                    read_file >> array[i];
                }
            // calling the merge sort function and print within to the loop makes
            // sure that each time the temp array is filled it gets sorted and printed in the same iteration
            // since the temp array gets filled with new values every iteration of the while loop.
            merge_sort(array, 0, array_size - 1);
            print_array(array, sorted, array_size);
            array_size = 0; // reset the value of array size so that, reintializing
        }
         sorted.close(); // closes the file that is used for writing 
    }
    return 0;
}

/*********************************************************************
** Function: merge
** Description: merges 2 sub arrays into one
** Parameters: array pointer, int left, middle and right
** Pre-Conditions: must be a valid array pointer, right ints passed in
** Post-Conditions: the inputted array will be ordered
*********************************************************************/ 
void merge(int *array, int left, int middle, int right)
{
    int i = 0, j = 0, k = 0;
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
 /*********************************************************************
** Function: merge_sort
** Description: sorts the array passed in using merger sort algo
** Parameters: array pointer, int left and right
** Pre-Conditions: must be a valid array
** Post-Conditions: passed in array is sorted
*********************************************************************/ 
void merge_sort(int *array, int left, int right){
    
    if (left < right) { //condition for 
        
        //divid and conquere characteristis here.
        int middle = (left + right) / 2; // searchs for the half point of the passed in array
 
      
        merge_sort(array, left, middle); //recursvily sorts left half
        merge_sort(array, middle + 1, right); //recusily sorts right half
 
        merge(array, left, middle, right); // the merge function is called put everything together once the recursion breaks
    }
}
 /*********************************************************************
** Function: print_array
** Description: prints out passed in array onto a file
** Parameters: array pointer, ofstream object, and int array size
** Pre-Conditions: must have be a valid file, array.
** Post-Conditions: stream file will have printed results on it
*********************************************************************/ 
void print_array ( int *array, ofstream& sorted, int array_size) {

    // prints out an array using a for loop
    for (int i = 0; i < array_size; i++ ){
        sorted << ' ' << array[i]; // instead of cout ofstream file writing is used.
    }
    sorted << endl;
}
