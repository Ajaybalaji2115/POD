/*Single File Programming Question
Problem Statement



﻿Given a text string (txt) and a pattern string (pat), the task is to find all occurrences of the pattern in the text using the Naive Pattern Searching algorithm. 



﻿The Naive Pattern Searching algorithm compares the pattern with every possible substring of the text to find matches.

Input format :
The first line of input consists of the text string, txt.

The second line consists of the pattern string, pat.

Output format :
The output prints the indices where the pattern is found in the given text (index starts from 0).

If the pattern is not found, it prints "Pattern not found in the text."



Refer to the sample output for the exact format.

Code constraints :
The input strings (txt) and (pat) consist of lowercase and/or uppercase letters.

The maximum length of the input strings is 105.

Sample test cases :
Input 1 :
AABAACAADAABAAABAA
AABA
Output 1 :
Pattern found at index 0
Pattern found at index 9
Pattern found at index 13
Input 2 :
Hello World
World
Output 2 :
Pattern found at index 6
Input 3 :
The quick brown fox jumps over the lazy dog
Cat eat
Output 3 :
Pattern not found in the text.
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
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    int l=txt.length();
    int l1=pat.length();
    bool cond=false;
    for(int i=0;i<=l-l1;i++)
    {
        string str="";
      
        for(int j=0;j<l1;j++)
        {
            str+=txt[i+j];
        }
        if(str==pat)
        {
            cout<<"Pattern found at index "<<i<<endl;
            cond=true;
        }
    }
    if(cond==true)
    return 0;
    cout<<"Pattern not found in the text.";
    
}
