/*Single File Programming Question
Problem Statement



Reema, a computer science student, is learning about Huffman coding, a widely used algorithm for lossless data compression. She wants to implement the Huffman coding algorithm to understand it better and generate Huffman codes for a given set of characters and their frequencies.



Write a program that takes a set of characters along with their frequencies and generates the Huffman codes for each character.

Input format :
The first line of input consists of an integer n, representing the number of characters in the list.

The next n lines consist of a character and its corresponding integer frequency, separated by a space.

Output format :
The output displays the generated Huffman codes for each character in the following format: <character>: <Huffman_code>



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:

1 ≤ n ≤ 26 (number of characters)

1 ≤ frequency ≤ 100 (frequency of each character)

Sample test cases :
Input 1 :
6
a 12
b 2
c 7
d 13
e 14
f 85
Output 1 :
b: 0000
c: 0001
a: 001
d: 010
e: 011
f: 1
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Fill your code here
C++ (17)
theme
instruction
 

Clear*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char character;
    int frequency;
    Node* left,*right;
    Node(char c,int freq):character(c),frequency(freq),left(nullptr),right(nullptr){}
};
struct Compare
{
    bool operator()(Node* a,Node* b)
    {
        return a->frequency>b->frequency;
    }
};
void generateCodes(Node* root,string code,unordered_map<char,string>&huffmanCodes)
{
    if(!root)
    return;
    if(!root->left && !root->right)
    {
        huffmanCodes[root->character]=code;
    }
    generateCodes(root->left,code+"0",huffmanCodes);
    generateCodes(root->right,code+"1",huffmanCodes);
}
int main()
{
    int n;
    cin>>n;
    priority_queue<Node*,vector<Node*>,Compare>pq;
    for(int i=0;i<n;i++)
    {
        char ch;
        int freq;
        cin>>ch>>freq;
        pq.push(new Node(ch,freq));
    }
    while(pq.size()>1)
    {
        Node* left=pq.top();
        pq.pop();
        Node* right=pq.top();
        pq.pop();
        Node* newNode=new Node('\0',left->frequency+right->frequency);
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }
    Node* root=pq.top();
    unordered_map<char,string>huffmanCodes;
    generateCodes(root,"",huffmanCodes);
    for(auto pair:huffmanCodes)
    {
        cout<<pair.first<<": "<<pair.second<<endl;
    }
    
}
