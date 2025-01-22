/*Single File Programming Question
Problem Statement



Write a program to implement an optimal binary search tree using dynamic programming.



Given a sorted array key [0... n-1] and an array freq [0... n-1] of frequency counts, where freq [i] is the number of searches for key [i], Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.



Note: Cost of a BST node: level of that node * frequency. The level of the root is 1.

Input format :
The first line of the input is the value of n.

The second line of input is the keys separated by a single space.

The last line of input is the frequency separated by a single space.

Output format :
The output prints the cost of the optimal binary search tree.

Sample test cases :
Input 1 :
3
10 12 20
34 8 50
Output 1 :
Cost of Optimal BST is 142
Input 2 :
5
15 18 20 25 28
30 12 5 10 8
Output 2 :
Cost of Optimal BST is 130
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
*/
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int optimalBST(int keys[],int freq[],int n)
{
    vector<vector<int>>dp(n,vector<int>(n,0));
    vector<vector<int>>sum(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        sum[i][i]=freq[i];
        for(int j=i+1;j<n;j++)
        {
            sum[i][j]=sum[i][j-1]+freq[j];
        }
    }
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i+len-1;
            if(len==1)
            {
                dp[i][j]=freq[i];
            }
            else
            {
                dp[i][j]=INT_MAX;
                for(int r=i;r<=j;r++)
                {
                    int cost=((r>i)?dp[i][r-1]:0)+((r<j)?dp[r+1][j]:0)+sum[i][j];
                    dp[i][j]=min(dp[i][j],cost);
                }
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    cin>>n;
    int keys[n],freq[n];
    for(int i=0;i<n;i++)
    {
        cin>>keys[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>freq[i];
    }
    cout<<"Cost of Optimal BST is "<<optimalBST(keys,freq,n)<<endl;
}
