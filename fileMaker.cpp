/*******************************************************************************
 **  fileMaker.cpp
 ** WeiHao Kuang
 ** 08/14/2018
 ** bin.txt file maker
 ** No Input
 ** Outputs a bin.txt file used for bin.cpp
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** The function of this program is to create a bin.txt file for bin.cpp to use
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main () {

    // variable initialization
    int bin_cap = 0; // bin_cap variable
    int items = 0; // iterms varibale

    ofstream output; // out stream variable object

    output.open("bin.txt"); // opens file to write to

    srand(time(NULL)); // seeding the rando generator

    output << "30" << endl; // there will be a static 30 sets of rando numbers

    // loop runs for 30 times and creates number set that are similar to style
    // as the homwork handout
    for ( int i = 0; i < 30; i++) {

        bin_cap = rand() % 100 + 1 ; // capped at 100 for bin_cap
        items = rand() % 65 + 1 ; // capped at 65 for items amount
        int array[items]; // create a static array for item printing


        output << bin_cap << endl; //outputs to file, the bin_cap amount
        output << items << endl; // outputs to file, the items amount
        // loops runs for items amount of time, and the each element in the
        // array is randomly generated and the number does not exceed that of
        // bin_cap
        for ( int j = 0; j < items; j++) {
            array[j] = rand() % bin_cap;
            output << array[j] << ' ';
        }
        output << endl;
    }

    return 0;
}
