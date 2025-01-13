/*Single File Programming Question
Problem Statement



﻿In a clandestine world of spies and covert communication, a group of operatives needs to develop a Huffman coding system to encode and decode their top-secret messages. Each operative is assigned a unique character along with its frequency of occurrence in their messages. 



Your task is to assist them in building this Huffman coding system and help them encode and decode their classified messages.

Input format :
The first line contains an integer N, representing the number of characters and their corresponding frequencies.

The next N lines contain a character and an integer separated by a space, indicating the character and its frequency of occurrence.

The last line contains a string representing the secret message to be encoded.

Output format :
For each character in N lines, the output prints its character and its Huffman code.

The next line prints the encoded message as a string.

The last line prints the decoded message as a string.



Refer to the sample outputs for better understanding and formatting.

Code constraints :
The test cases fall under the following constraints:

1 ≤ N ≤ 10

Sample test cases :
Input 1 :
5
A 5
B 9
C 12
D 13
E 16
HELLO, WORLD!
Output 1 :
C: 00
D: 01
A: 100
B: 101
E: 11
1101
ED
Input 2 :
3
X 1
Y 2
Z 3
XYZXYZ
Output 2 :
Z: 0
X: 10
Y: 11
1011010110
XYZXYZ
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int freq;
    Node *left,*right;
    Node(char character,int frequency):ch(character),freq(frequency),left(nullptr),right(nullptr){}
};
struct Compare
{
    bool operator()(Node* left,Node* right)
    {
        return left->freq>right->freq;
    }
};
void generateCodes(Node* root,const string& code,unordered_map<char,string>&huffmanCodes)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    {
        huffmanCodes[root->ch]=code;
    }
    generateCodes(root->left,code+"0",huffmanCodes);
    generateCodes(root->right,code+"1",huffmanCodes);
}
Node* buildHuffmanTree(const vector<pair<char,int>>&charFreqs)
{
    priority_queue<Node*,vector<Node*>,Compare>minHeap;
    for(const auto&pair:charFreqs)
    {
        minHeap.push(new Node(pair.first,pair.second));
    }
    while(minHeap.size()>1)
    {
        Node* left=minHeap.top();
        Node* right=minHeap.top();
        Node* merged=new Node('\0',left->freq+right->freq);
        merged->left=left;
        merged->right=right;
        minHeap.push(merged);
    }
    return minHeap.top();
}
string encodeMessage(const string& message,const unordered_map<char,string>&huffmanCodes)
{
    string encodedMessage="";
    for(char ch:message)
    {
        if(huffmanCodes.find(ch)!=huffmanCodes.end())
        {
            encodedMessage+=huffmanCodes.at(ch);
        }
    }
    return encodedMessage;
}
string decodeMessage(Node* root,const string& encodedMessage)
{
    string decodedMessage="";
    Node* current=root;
    for(char bit:encodedMessage)
    {
        if(bit == '0')
        current=current->left;
        else
        current=current->right;
        if(current->left==nullptr && current->right==nullptr)
        {
            decodedMessage+=current->ch;
            current=root;
        }
    }
    return decodedMessage;
}
int main()
{
    int N;
    cin>>N;
    vector<pair<char,int>>charFreqs(N);
    for(int i=0;i<N;i++)
    {
        cin>>charFreqs[i].first>>charFreqs[i].second;
    }
    string message;
    cin.ignore();
    getline(cin,message);
    Node* root=buildHuffmanTree(charFreqs);
    unordered_map<char,string>huffmanCodes;
    generateCodes(root,"",huffmanCodes);
    for(const auto& pair:huffmanCodes)
    {
        cout<<pair.first<<": "<<pair.second<<endl;
    }
    string encodeMsg=encodeMessage(message,huffmanCodes);
    cout<<encodeMsg<<endl;
    string decodeMsg=decodeMessage(root,encodeMsg);
    cout<<decodeMsg<<endl;
}
