/*Single File Programming Question
Problem Statement



Write a program to implement a string search algorithm called the Z algorithm. The search method takes two string arguments, text, and pattern, and finds all occurrences of the pattern in the text using the Z algorithm. The Z algorithm preprocesses the pattern and text to construct an array Z that stores the length of the longest substring starting from each position that matches the pattern.

Input format :
The first input consists of a string.

The second input consists of the string pattern to search.

Output format :
The output displays the indices where the pattern is found.



Refer to the sample output for the formatting specifications.

Sample test cases :
Input 1 :
iamneo at Coimbatore
iamneo
Output 1 :
Pattern found at index 0
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
  // You are using GCC*/
#include<bits/stdc++.h>
using namespace std;
void constructLps(string &pat,vector<int>&lps)
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<pat.length())
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
vector<int>search(string &pat,string &txt)
{
    int n=txt.length();
    int m=pat.length();
    vector<int>lps(m);
    vector<int>res;
    constructLps(pat,lps);
    int i=0,j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++,j++;
            if(j==m)
            {
            res.push_back(i-j);
            j=lps[j-1];
            }
        }
        else
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
        
    }
    return res;
}
int main()
{
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    vector<int>res=search(pat,txt);
    for(int i=0;i<res.size();i++)
    {
        cout<<"Pattern found at index "<<res[i]<<endl;
    }
    
}
