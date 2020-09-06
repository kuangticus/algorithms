# AOA-HW2

In this zip there will be:

stoogesort.cpp

stoogeTime.cpp

README.md

/*************************************************************************************************************************/

CPP file notes: 

stoogesort.cpp and stoogeTime.cpp fullfil question 5 of the homework.

stoogesort.cpp is a program that uses the stooge sort alogritm to sort an array into ascending order.

stoogeTime.cpp is a program that captures the runtime of the stooge sort algorithm based on differt n sizes that range from 500-7500

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ stoogesort.cpp /* after running the program the output file will be "stooge.out" */

g++ stoogeTime.cpp /* after running the program the output file will be "stoogeTime.txt" */

/*************************************************************************************************************************/

Format of the tables in mergeTime.out and insertTime.out

| n size | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | Average time (mS) |

this format will be true for both mergeTime.out and insertTime.out, the n sizes that will be output range from 500 - 7500 on increments of 500 everytime.

/**************************************************************************************************************************/

Note: Since the n sizes are rather big for the stooge sort algorithm in stoogeTime.cpp the the program will take a some time to run.
The reason that I used the larger n sizes is because they show the relationship between n size and runtime very well on the graphs.
