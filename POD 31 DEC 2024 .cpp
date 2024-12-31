/*Write a program to implement a basic B-Tree data structure and perform various operations on it. 



The program should support the following operations:

Insert: Allow the user to insert values into the B-tree.
In-order traversal: Display the values in the B-tree in ascending order using an in-order traversal.
Delete: Enable the user to remove values from the B-tree.
Display Remaining Values: After performing deletion operations, the program should display the remaining values in the B-tree.
Input format :
The first line of input consists of an integer N, representing the number of elements to be inserted into the B tree.

The second line consists of N space-separated integers, representing the elements to be inserted into the tree.

The third line consists of an integer representing the element to delete.

Output format :
The first line of output prints: "The values inserted in the B-tree are: ", followed by the numbers in in-order traversal separated by a space.

The second line of output prints: "After deletion the values in the B-tree: ", followed by the numbers in in-order traversal separated by a space after the specified deletion.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 20

1 ≤ elements ≤ 150

Sample test cases :
Input 1 :
5
12 8 4 18 6
12
Output 1 :
The values inserted in the B-tree are: 4 6 8 12 18 
After deletion the values in the B-tree: 4 6 8 18 
Input 2 :
8
2 3 10 8 6 4 21 78
21
Output 2 :
The values inserted in the B-tree are: 2 3 4 6 8 10 21 78 
After deletion the values in the B-tree: 2 3 4 6 8 10 78 
Input 3 :
5
14 25 65 97 37
59
Output 3 :
The values inserted in the B-tree are: 14 25 37 65 97 
After deletion the values in the B-tree: 14 25 37 65 97 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/





/*Single File Programming Question
Problem Statement



Given the weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays, val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items, respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that the sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it.



Solve this problem using dynamic programming.

Input format :
The first line of input represents the number of items.

The second line of input consists of the values of each item separated by spaces.

The third line of input consists of the weights of each item separated by spaces.

The fourth line of input consists of an integer, which represents the maximum capacity of the knapsack.

Output format :
The output prints the maximum value of items that can be held by the knapsack.

Sample test cases :
Input 1 :
3
60 100 120
10 20 30
50
Output 1 :
220
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
