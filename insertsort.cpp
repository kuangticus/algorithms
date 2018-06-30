/*******************************************************************
 ** insertsort.cpp 
 ** WeiHao Kuang
 ** 06/28/2018
 ** Insertion sort algorithm with input and out file streams
 ** Input file "data.txt"
 ** Output file "insert.out"
*******************************************************************/
#include<iostream>
#include<fstream>

using namespace std;

void insertion_sort(int*, int); 
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
    sorted.open("insert.out"); // opens a file named "insert.out" store the sorted array values

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
            insertion_sort (array, array_size); 
            print_array(array, sorted, array_size);
        }
    }
    sorted.close(); // closes the file that is used for writing 


    return 0;
}
/*********************************************************************
** Function: insetion_sort
** Description: using the insertion algoritm sorts int array (ascending)
** Parameters: unsort pointer (array), and  int array_size 
** Pre-Conditions: Must have a valid array passed int, and a non-neg int
** Post-Conditions: The unsorted array will be sorted
*********************************************************************/ 
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