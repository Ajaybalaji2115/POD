/*Single File Programming Question
Problem Statement

MONEY HEIST!

You are the PROFESSOR of a professional robbers group. And now you are planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money in each house. As you are the professor, plan smart to get the maximum amount of money you can rob tonight without alerting the police.

BELLA CIAO !!!



Example

Input

5

2 7 9 3 1

Output

12

Explanation

Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).

Total amount you can rob = 2 + 9 + 1 = 12.

Input format :
Number of Houses

Amount in each house represented by an array

Output format :
An integer result

Sample test cases :
Input 1 :
5
2 7 9 3 1
Output 1 :
Maximum loot possible : 12
Input 2 :
6
3 2 1 4 5 6
Output 2 :
Maximum loot possible : 13
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
  / You are using GCC*/
#include<bits/stdc++.h>
using namespace std;
void solve(int i,int n,vector<int>&v,vector<int>&arr,vector<vector<int>>&v1)
{
    if(i==n)
    {
        v1.push_back(v);
       
        return;
    }
    v.push_back(arr[i]);
    solve(i+1,n,v,arr,v1);
    v.pop_back();
    solve(i+1,n,v,arr,v1);
}
int find(int num,int num1,vector<int>&arr,int n)
{
    int k=0,j=0;
    for(int  i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            k=i;
        }
        if(arr[i]==num1)
        {
            j=i;
        }
    }
return (j-k);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    vector<vector<int>>v1;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(0,n,v,arr,v1);
    int maxima=INT_MIN;
    for(auto subset:v1)
    {
            if(subset.empty())
            continue;
        int sum=0;
        int z=subset.size();
        for(int j=0;j<z-1;j++)
        {
            if(find(subset[j],subset[j+1],arr,n)==1)
            continue;
            else
            sum+=subset[j];
        }
        sum+=subset.back();
        maxima=max(maxima,sum);
    }
    cout<<"Maximum loot possible : "<<maxima;
}
