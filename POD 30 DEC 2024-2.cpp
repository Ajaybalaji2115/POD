/*Single File Programming Question
Problem Statement:



Given an array of N integers, and a number sum, find the number of pairs of integers in the array whose sum is equal to sum.



Note: Use HashMap to solve this problem.



Example:

If the input is arr[] = {1, 5, 7, -1} and the sum is 6, then the output is 2.

Explanation: The sum 6 pairs are (1, 5) and (7, -1).

Input format :
The first line of the input is N, which is the number of elements in that array, followed by the N elements.

The next line of the input consists of the sum.

Output format :
The output prints the count of pairs with the given sum.



Refer to the sample input and output for the format specifications.

Sample test cases :
Input 1 :
4
1 5 7 -1 
6
Output 1 :
Count of pairs 6 is 2
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count=0;
    
    for(int i=0;i<n;i=i+2)
    {
      if(i+1<n)
      {
          int sum=arr[i]+arr[i+1];
          if(sum==k)
          count++;
      }
      else
      {
          if(arr[i]==k)
          count++;
      }
    }
    cout<<"Count of pairs "<<k<<" is "<<count;
  
}
