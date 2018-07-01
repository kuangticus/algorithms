# AOA-HW1

In this zip there will be:

insertsort.cpp

mergesort.cpp

insertTime.cpp

mergeTime.cpp

insertTime.txt

mergeTime.txt

merge_best_worst.cpp

insert_best_wortst.cpp

README.md

/*************************************************************************************************************************/

CPP file notes:

insertsort.cpp and mergesort.cpp fullfil question 4 of the homework.

insertTime.cpp and mergeTime.cpp fullfill question 5(a) of the homework, also in
the written homework I will explain what I did to achieve to count the runtimes. In this zip
I also included the tables that I will be using to graph the runtime of both the merge sort and
insert sort alogrithms. I will also include the tables insertTime.out and megerTime.out with 
the written homework.

merge_best_worst.cpp and insert_best_worst.cpp are cpp files that fufill the requirement of the the extra credit from 
Homework 1.

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ insertsort.cpp /* after running the program the output file will be "insert.out" */
g++ mergesort.cpp /* after running the program the output file will be "merge.out" */
g++ insertTime.cpp /* after running the program the output will be on the console/terminal and file "insertTime.txt" */
g++ mergeTime.cpp /* after running the program the output will be on the console/terminal and file "mergeTime.txt" */
g++ merge_best_worst.cpp
g++ insert_best_worst.cpp

/*************************************************************************************************************************/

Format of the tables in mergeTime.out and insertTime.out

| n size | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | Average time (mS) |

this format will be true for both mergeTime.out and insertTime.out, the n sizes that will be output range from 5000 - 70000
on increments of 5000 everytime.

As for the tables created from merge_best_worst.cpp and insert_best_worst.cpp that formatting is:

| Case Condition | trial 1 time (mS) | trial 2 time (mS) | trial 3 time (mS) | Average time (mS) |

/**************************************************************************************************************************/ 
