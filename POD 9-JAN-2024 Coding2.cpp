/*
Single File Programming Question
Problem Statement



Given a 3x3 board with 8 tiles (numbered from 1 to 8) and one empty space (0), your task is to move the tiles using sliding moves so that the board reaches the desired goal state. A sliding move consists of moving a tile adjacent (horizontally or vertically) to the empty space into the location of the empty space. 



The goal is to use the vacant space to arrange the numbers on the tiles such that they match the final arrangement.



Write a program to solve the 3x3 sliding puzzle and output the moves required to solve the puzzle, along with the final solved state.



The final arrangement is fixed as,

[1, 2, 3], 

[5, 8, 6], 

[0, 7, 4].

Input format :
The input consists of a 3x3 puzzle.

Each line contains three space-separated integers, representing the numbers in the puzzle grid.

The numbers 1 through 8 represent the tiles, and 0 represents the empty space.

Output format :
The output displays each sequence of moves required to solve the puzzle, separated by a new line, followed by the final solved state of the puzzle.



﻿Refer to the sample output for formatting specifications.

Code constraints :
Tiles can only be moved one at a time.

Sample test cases :
Input 1 :
1 2 3
5 6 0
7 8 4
Output 1 :
1 2 3 
5 6 0 
7 8 4 

1 2 3 
5 0 6 
7 8 4 

1 2 3 
5 8 6 
7 0 4 

1 2 3 
5 8 6 
0 7 4 

Input 2 :
1 2 3
5 8 6
7 0 4
Output 2 :
1 2 3 
5 8 6 
7 0 4 

1 2 3 
5 8 6 
0 7 4 

Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
