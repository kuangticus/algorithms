# AOA-HW8

In this zip there will be:

bin.cpp

fileMaker.cpp // helper program used to create bin.txt

bin.txt

binIP.cpp // not included yet

binEC.txt // used to test the EC program

README.md

/*************************************************************************************************************************/

CPP file notes:

bin.cpp fulfils question 1 of the homework.

binIP.cpp fulfulls EC of the homework.

fileMaker.cpp is used to make the bin.txt file for uses in binIP.cpp and bin.cpp

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ bin.cpp /* after running the program the output will be on the terminal */

g++ fileMaker.cpp /* after running the program the output file will be "bin.txt" */

g++ binIP.cpp /* after running the program the output will be on file "binIP.lp" */

/*************************************************************************************************************************/

Format of the output from bin.cpp:

| First-Fit (FF): bins used | First-Fit-Decreasing: bins used| 

Format of the file from binIP.cpp:

I will in the format to linear programming problems made for LINDO
the format will be similar to the solution found on this wikipeida page:
https://en.wikipedia.org/wiki/Bin_packing_problem

/**************************************************************************************************************************/

Text files

bin.txt will be made from the program fileMaker.cpp the file can be used for both bin.cpp and binIP.cpp

binEC.txt wil be used for binIP.cpp which is modified to be a little smaller so it will be able to be tested using LINDO
