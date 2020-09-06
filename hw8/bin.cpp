/*******************************************************************************
 ** bin.cpp
 ** WeiHao Kuang
 ** 08/14/2018
 ** minimum container program
 ** bin.txt
 ** terminal output
 ** Citiation: used as reference (below)
 ** https://en.wikipedia.org/wiki/Bin_packing_problem
 ** https://arxiv.org/ftp/arxiv/papers/1508/1508.01376.pdf
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>

using namespace std;

int first_fit (int*, int, int); // FF
int first_fit_decrease(int*, int , int ); // FFD

/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main() {

    //intializing variables
    ifstream input; // input stream variable output
    input.open("bin.txt"); // input stearm file open
    int bin_cap, items, n, sets, comp1, comp2;
    int performance = 0;

    input >> sets; // sets the loop iterations

    // loop goes for the amount of sets there
    for ( int i =0; i < sets; i++) {

        input >> bin_cap; // states the bin_cap for current set
        input >> items; // states the items amount
        int weight_array[items]; // create an array items sized big.

        //loop goes to fill up the weights array with values from external file
        for ( int j = 0; j < items; j++) {
            input >> weight_array[j]; // fills the array
        }

        // n is used for bin calculation later in the program
        n = sizeof(weight_array) / sizeof(weight_array[0]);

        // calling the first_fit and first_fit_decrease function and displaying results

        comp1 = first_fit(weight_array, n, bin_cap);
        comp2 = first_fit_decrease(weight_array, n, bin_cap);


        cout << "Test Case " << i + 1 << " First Fit : "
             << comp1;

        cout << " - First Fit Decreasing : "
             << comp2 << endl;

        cout << endl;

        // counts amount of time FFD beats FF
        if ( comp2 < comp1 )
            performance++;

    }
    cout << "First-Fit-Decreasing (FFD) is the most effiecient of the two algorithms: "
         << endl;
    cout << "It beats First_Fit (FF) " << performance << " out of the 30 trials taken "
         << endl;
    cout << "If FFD doesn't beat beat FF on a trial then they are tied." << endl;

    return 0;
}
/*******************************************************************************
** Function: first_fit
** Description: this is the first fit function find the minimum bins needed
** Parameters: weight_array, int n and bin_cap
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: minimum bin used found
** Return: minimum bins used
*******************************************************************************/
int first_fit(int weight_array[], int n, int bin_cap) {
    // result initialization; this counts the bins used
    int result = 0;

    // array used to store remaining space in bins,
    // there can be no more than n bins
    int bin_rem[n];

    // places the items from weight array one by one
    for (int i = 0; i < n; i++) {

        // used to find the first bin that can accomodate the
        // weight_array[i]'s weight.
        int j;
        for ( j = 0; j < result; j++) {
            if (bin_rem[j] >= weight_array[i]) {
                bin_rem[j] = bin_rem[j] - weight_array[i];
                break;
            }
        }

        // if no bin that is avaibale to accomodate weight_array[i]
        // make a new bin, increase bins used tally marking.
        if (j == result) {
            bin_rem[result] = bin_cap - weight_array[i];
            result++; // increase tally
        }
    }
    return result;
}
/*******************************************************************************
** Function: first_fit_decrease
** Description: usued to find the minimum number of bins used with ordered
** (descending order) list
** Parameters: weight_array array, int n, int bin_cap
** Pre-Conditions: must have a weight_array present and first_first function
** Post-Conditions: finds the minimum amount of bins used
** Return: The minimum amount of bins used
*******************************************************************************/
int first_fit_decrease(int weight_array[], int n, int bin_cap) {
    // Using the premade sorting algorithm from algorithm library
    // time complexity is O(nlogn), to sort the weight array into
    // descending order.
    sort(weight_array, weight_array + n, std::greater<int>() );

    // Now call first fit for the newly sorted weight array
    // add it will return the minimum bins used
    return first_fit(weight_array, n, bin_cap);
}
