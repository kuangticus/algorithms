# AOA-HW3

In this zip there will be:

change.cpp

changeTime.cpp

amount.txt

changeTime.txt

README.md

/*************************************************************************************************************************/

CPP file notes:

change.cpp and amount.txt fullfil question 5 of the homework.

change.cpp is a program that looks for the minimum change that can be used to make a specified amount.

changeTime.cpp and changeTime.txt fullfill question 6 of the homework

changeTime.cpp times how long it take to find the minimum change, when n and A are both changing. 

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ change.cpp /* after running the program the output file will be "change.txt" */

g++ changeTime.cpp /* after running the program the output file will be "changeTime.txt" */

/*************************************************************************************************************************/

Format of the tables in changeTime.txt

| Time (mS) | A value | n value  |

this format will be true for changeTime.txt and any table that are made from changeTime.cpp, the A sizes will range from 2900-10500 on increments of 2500, and n values will range from 0 - 8000 on increments of 400, the value inside the denmomination n will be randomly generated modded by 200.

Format of change.txt will be the same as it is described in the homework hand out:

1 2 5 // denomination (n)
10 // amount that is needed in change
0 0 2 // which coins from n where used to make the minimum change
2 // minimum coins used to make the change

/**************************************************************************************************************************/
