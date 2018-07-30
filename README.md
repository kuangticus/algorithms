In this zip there will be:

wrestler.cpp

wrestler1.txt

wrestler2.txt

wrestler3.txt

wrestler_HW_ex.txt

README.md

/*************************************************************************************************************************/

CPP file notes:

wrestler.cpp fullfils question 4 of the homework looks for the bipartiteness of the graph, 
and displays whether the graph is bipartite or not.

/************************************************************************************************************************/

CPP compile notes and running notes

All of th CPP files like so:

g++ wrestler.cpp // after running the program the output will be printed onto the terminal.

/*************************************************************************************************************************/

Output Formatting

First line: Biparitite (True or False)

Second line: Babyface: member names

Third line: Heel: memeber names

/**************************************************************************************************************************/

Text files:

all of the textfile that are included in this zip file are used to run and test the program, 

Correct output for:

wrestler1.txt is:

// Impossible

wrestler2.txt is:

Yes Possible
Babyfaces: Bear Maxx Duke
Heels: Killer Knight Samson

wrestler3.txt is:

Yes possible
Babyfaces :  A   B   C   D   E
Heels :  V   W   X   Y   Z

wrestler_HW_ex.txt is:

Yes
Babyfaces: Ace Jax Stone
Heels: Biggs Duke


/**************************************************************************************************************************/

Notes for Problems 4:

Remarks about the pseudo-code and how it runs, and the algorithms in general:

The last-to-start approach for activity selection's layout and structure of the code is very similar to that of the first-to-finish approach. The difference between the two implementation will be their obvious constraint difference; which leads to a slight change in logic when it comes to sorting the the start and stop times. When sorting, last-to-start approach start times are sorted in descending order, in my version of the algorithm. While, on the other hand the first-to-finish implementation sorts its finish times in ascending order. This changes how each algorithm functions when searching for the compatible activities. My implementation of the last-to-start approach I defined a structure with order value, start and finish times. Then I would sort them in descending order based on starting time, and run them through a comparison based on the start to finish times of each activity compared to the next one, and then the algorithm will choose the best activities for that day.

Psuedo-code for the algorithm will be in section/question for the homework right up:

Runtime Analysis:

As for the average runtime complex of this algorithm it is $O(n^2)$ when most of the structs are sorted upon in the two for loops. It is only $O(n)$ when the structs come in pre-sorted. These runtime complexities come from the 2 nested for loops used to sort the array; other implementations may have better or worst runtime complexities based on how the structs are sorted.