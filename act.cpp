/*******************************************************************************
 ** act.cpp
 ** WeiHao Kuang
 ** 07/19/2018
 ** activity selector based on latest start time
 ** Input file "act.txt"
 ** Output file "actResults.txt", and terminal output
 ** Citiation: used as reference (below)
 ** https://www.dyclassroom.com/greedy-algorithm/activity-selection-problem
 ** https://en.wikipedia.org/wiki/Activity_selection_problem
*******************************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<vector>

using namespace std;

/*******************************************************************************
 ** struct activity
 ** stores the order, start, and finish information for each of the activities
*******************************************************************************/
struct activity {
    int order;
    int start;
    int finish;
};

void act_select( activity*, int, int*, ofstream&);
void printer (vector<int>, int, int*, ofstream&);
void act_sort( activity*, int);

/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main () {
    // initallizing the in stream and outstream
    ifstream input; // in stream
    ofstream output; //out stream
    int size, set_counter = 1; // used for loop and numbering logic

    // opening the input file act.txt
    //opening the outfile actResults.txt
    input.open("act.txt");
    output.open("actResults.txt");

    // the following conditional checks to see if the input file is open and
    // can be used to read of data: error checking
    if ( input.good() )
        while ( !input.eof() ) { //if the file is not ended continue
            input >> size; // read the first solo line displaying amount in set
            activity storage[size]; // makes array of set size.

            // nested for loops here are used to input the data into the
            // the array in there respective spots
            // runs the amound out activies in set
            for ( int i = 0; i < size; i++ ) {
                for ( int j =0; j < 3; j++ ){ // runs 3 times to fill struct

                    if ( j == 0 ){ // assigns the order of the activity
                        input >> storage[i].order ;
                    }
                    else if ( j == 1){ //assigns the start time of activity
                        input >> storage[i].start;
                    }
                    else{ // assigns the ending time of activity
                        input >> storage[i].finish;
                    }
                }
            }
            // calls the sorting funcion to sort unsorted array
            act_sort (storage, size);
            // this function call makes the activity choices
            act_select( storage, size, &set_counter, output);
            size = 0;
        }

    return 0;
}
/*******************************************************************************
** Function: act_select
** Description: used to selected the activities the a person can do using
** latest to start logic instead of first to finish logic.
** Parameters: storage structure, int size, int *set_counter, output_stream output
** Pre-Conditions: must have all of the parameters and the struct must no be empty
** Post-Conditions: will select the activities, and display them on terminal and file
*******************************************************************************/
void act_select (activity *storage, int size, int *set_counter, ofstream &output) {
    int i = 0;
    vector<int> holder; // creates a local vector used to output results
    holder.push_back(storage[i].order); // pushing the first result into vector
    // this for loop is responisble for deciding which activities will be
    // choosen
    for( int j = 1; j < size; j++) {
        // if the start time is greaer then the finish time of the
        // value below it then select (push in vector) the current activity
        if(storage[i].start >= storage[j].finish) {
            holder.push_back(storage[j].order); // selectin actitivity
            i = j; // increments to move to rest of the data
        }
    }
    // calling the printer function to display the results of the algorithm
    printer (holder, holder.size(), set_counter, output);
    cout << endl;
    output << endl;
}
/*******************************************************************************
** Function: printer
** Description: the printing process of the program, used to display the results
** to terminal and an output file.
** Parameters: vector<int> holder, int size, int* set, ofstream output
** Pre-Conditions: files must be open, and holder must exist, set is not NULL
** Post-Conditions: will print out the result to the the inputted data
*******************************************************************************/
void printer (vector<int> holder, int size, int* set, ofstream &output) {
    // below is a bunch of ouptut lines to the terminal and the output file
    // to terminal used cout
    // to output file used output
    cout << "Set " << *set << endl; // terminal
    output << "Set " << *set << endl; // output file
    cout << "Numbers of activities selected = " << size << endl;
    output << "Numbers of activities selected = " << size << endl;
    cout << "Activities: ";
    output << "Activities: ";
    // loop runs the size of the vector to ensure that the right change_amount
    // of numbers are outputted
    for ( int i = size-1; i >= 0; i--){
        cout << holder[i] << ' ';
        output << holder[i] << ' ';
    }
    cout << endl;
    output << endl;
    *set = *set + 1; // incrementing set signifing the next set in writing
}
/*******************************************************************************
** Function: act_sort
** Description: used to sort the data incoming from highest start time to lowest
** Parameters: activity storage, and int size
** Pre-Conditions: struct must not be empty, and there is a number size
** Post-Conditions: the incoming storage struct will be sorted
*******************************************************************************/
void act_sort ( activity* storage, int size) {
    activity temp; // creating a temp struct to order things in the loop
    // loop runs the size of the struct array, to sort them by starting times,
    // from greatest to least.
    for(int i = 1; i < size; i++) { // outter loop deals with running through size
        for( int j = 0; j < size - 1; j++){ // inner loop deals with size - 1
            // if the number is bigger on j than next swap desecening order of
            // start time, largest to smallest.
            // bellow is the swaping lines.
            if(storage[j].start < storage[j+1].start) {
    			temp = storage[j];
    			storage[j] = storage[j+1];
    			storage[j+1] = temp; // assigning smaller number to latter index
    		}
    	}
    }
}
