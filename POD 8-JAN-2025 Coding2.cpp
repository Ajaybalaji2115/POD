/*Single File Programming Question
Problem Statement



You are given a string. Using a recursive function, you have to obtain different combinations of the string or in other words permutations of the given string and all the sub-strings in alphabetical order.



Note: The characters within the sub-string can be repeated.



Example



Input:

ABC



﻿Output:

AAA AAB AAC ABA ABB ABC ACA ACB ACC BAA BAB BAC BBA BBB BBC BCA BCB BCC CAA CAB CAC CBA CBB CBC CCA CCB CCC 

Input format :
The input consists of a string.

Output format :
The output prints the list of permuted strings, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
The input consists of uppercase characters and a maximum length of 4 characters.

Sample test cases :
Input 1 :
BD
Output 1 :
BB BD DB DD 
Input 2 :
ABC
Output 2 :
AAA AAB AAC ABA ABB ABC ACA ACB ACC BAA BAB BAC BBA BBB BBC BCA BCB BCC CAA CAB CAC CBA CBB CBC CCA CCB CCC 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
  // You are using GCC*/
#include<bits/stdc++.h>
using namespace std;
void generateCombinations(string input,string output,int length)
{
    if(output.length() == length)
    {
        cout<<output<<" ";
        return;
    }
    for(char c:input)
    {
        generateCombinations(input,output+c,length);
    }
}
int main()
{
    string input;
    getline(cin,input);
    int length=input.length();
    generateCombinations(input,"",length);
    
}
