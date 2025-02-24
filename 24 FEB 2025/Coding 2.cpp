/*Single File Programming Question
Problem Statement



The Floyd-Warshall Algorithm is for solving all pairs of shortest-path problems. The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 

Input format :
The first line of input represents the size N.

The next N*N Matrix represents the distance.

Note: The distance between one city and itself will be 0, and the distance will be 999 if there is no direct edge between the two cities.

Output format :
The output prints the shortest distance between every pair of cities.

If there is no shortest path between two cities, then print INF.



Refer to the sample output for formatting specifications.

Sample test cases :
Input 1 :
4
0 5 999 10
999 0 3 999
999 999 0 1
999 999 999 0
Output 1 :
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
  // You are using GCC*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
 int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i>j)
                {
                  arr[i][j]=-1;
                  break;
                }
                else 
                {
                    arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==-1)
            cout<<"INF ";
            else
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
