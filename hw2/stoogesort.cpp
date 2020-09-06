/*****************************************************************************
 ** stoogesort.cpp 
 ** WeiHao Kuang
 ** 07/3/2018
 ** Stoogesort algorithm, that sorts an array of ints
 ** Input file "data.txt"
 ** Output file "stooge.out"
 ** Citiation: https://www.geeksforgeeks.org/stooge-sort/ used for refernce
****************************************************************************/
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void stooge_sort(int*, int, int); 
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

    read_file.open("data.txt"); // opens a file named "data.txt" to read values from. 
    sorted.open("stooge.out"); // opens a file named "insert.out" store the sorted array values

    if(read_file.good()){ // checks the file opened, returns true of false
 
        while (!read_file.eof()) { // if not end of file keep reading, if end of file break
            read_file >> array_size; // read the first int in a line, to determine the size of the array needed
            int array[array_size]; // temp array for unsorted ints
            // filled the temp array, with the unsorted values from "data.txt"
                for (int i = 0; i < array_size; i++){
                    read_file >> array[i];
                }
            // insertion_sort and print_array are both called within the while loop, so that the
            // temp array that gets sorted will print in the same iteration since the array gets 
            // cleared every iteration.
            stooge_sort (array, 0, array_size - 1 ); 
            print_array(array, sorted, array_size);
            array_size = 0; // resets the array sizes to zero at the end reintializing
        }
    }
    sorted.close(); // closes the file that is used for writing 


    return 0;
}
/******************************************************************************
** Function: stooge_sort
** Description: using the stooge sort alogrithm that sorts to ascending order
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
******************************************************************************/ 
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
/*********************************************************************
** Function: print_array
** Description: prints the array that is passed in onto a file
** Parameters: array pointer, ofstream sorted, and int array_size
** Pre-Conditions: Must be a valid file opened and filled array. 
** Post-Conditions: array will be printed 
*********************************************************************/ 
void print_array ( int *array, ofstream& sorted, int array_size) {
    // print the array that is passed in out using a tradtional for loop
    for (int i = 0; i < array_size; i++ ){
        sorted << ' ' << array[i];
    }
    sorted << endl; // new line for .out docutment
}