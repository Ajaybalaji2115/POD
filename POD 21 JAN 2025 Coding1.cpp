/*Single File Programming Question
Problem Statement



You are given the task of efficiently assigning three workers to three tasks, to minimize the total cost associated with the assignments. 



Each worker can be assigned to exactly one task, and each task can be assigned to exactly one worker. The cost of assigning a worker to a task is provided in the form of a cost matrix.



Write a program to determine the minimum total cost for such assignments.



Example



Input: 

10 12 19

10 5 7

15 14 13



Output:

Minimum total cost: 28



Explanation:

There are 3 workers and 3 tasks. The cost matrix indicates the cost of assigning each worker to each task. The optimal assignments are:

Worker 1 to Task 1 (Cost: 10)
Worker 2 to Task 2 (Cost: 5)
Worker 3 to Task 3 (Cost: 13)
The total cost of these assignments is 10 + 5 + 13 = 28, which is the minimum possible total cost.

Input format :
The input consists of three lines with three space-separated integers each, representing a 3x3 matrix.

Each cell (i, j) of the matrix contains a non-negative integer representing the cost of assigning the ith worker to the jth task.

Output format :
The output displays the minimum total cost of the assignment.



Refer to the sample output for formatting specifications.

Code constraints :
0 ≤ elements of the matrix ≤ 100

Sample test cases :
Input 1 :
10 12 19
10 5 7
15 14 13
Output 1 :
Minimum total cost: 28
Input 2 :
34 56 17
25 16 27
34 18 31
Output 2 :
Minimum total cost: 51
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
  // You are using GCC*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    int min,sum=0;
    for(int i=0;i<3;i++)
    {
        min=arr[i][0];
        for(int j=1;j<3;j++)
        {
            if(min>arr[i][j])
            min=arr[i][j];
        }
        sum+=min;
    }
    cout<<"Minimum total cost: "<<sum;
}
