# AOA-HW3

In this zip there will be:

change.cpp

changeTime.cpp

nAchangeTime.cpp

amount.txt

README.md

/*************************************************************************************************************************/

CPP file notes:

change.cpp and amount.txt fullfil question 5 of the homework.

change.cpp is a program that looks for the minimum change that can be used to make a specified amount.

changeTime.cpp and changeTime.txt fullfill question 6 of the homework

changeTime.cpp times how long it take to find the minimum change, when n and A are both changing. 

nAchangeTime.cpp part of the code the fulfulls question 6 of the homework: this program looks for the T(nA) data table

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ change.cpp /* after running the program the output file will be "change.txt" */

g++ changeTime.cpp /* after running the program the output file will be "changeTime.txt" */

g++ nAchangeTime.cpp /* after running the program the output file will be "changeTime.txt" */

/*************************************************************************************************************************/
Textfile notes:

Format of the tables in changeTime.txt

For graphs T(n) table format:

| n value | Time (mS) |

For graphs T(A) table format:

| A value | Time (mS) |

For graphs T(aA) table format:

| Value of nA | Time (mS) |

Format of change.txt will be the same as it is described in the homework hand out:

1 2 5 // denomination (n)
10 // amount that is needed in change
0 0 2 // which coins from n where used to make the minimum change
2 // minimum coins used to make the change

/**************************************************************************************************************************/
