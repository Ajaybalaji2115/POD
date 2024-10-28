/*ingle File Programming Question
Problem Statement
You are given two strings s and sub. You are also given a 2D character array mappings where mappings[i] = [oldi, newi] indicates that you may perform the following operation any number of times:
Replace a character oldi of sub with newi.
Each character in sub cannot be replaced more than once.
Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings. Otherwise, return false.
A substring is a contiguous non-empty sequence of characters within a string.
Example 1:
Input: s = "fool3e7bar", sub = "leet", n=3, mappings = [["e","3"],["t","7"],["t","8"]]
Output: true
Explanation: Replace the first 'e' in sub with '3' and 't' in sub with '7'.
Now sub = "l3e7" is a substring of s, so we return true.
Example 2:
Input: s = "fooleetbar", sub = "f00l", n=1, mappings = [["o","0"]]
Output: false
Explanation: The string "f00l" is not a substring of s and no replacements can be made.
Note that we cannot replace '0' with 'o'.
Example 3:
Input: s = "Fool33tbaR", sub = "leetd", n=5, mappings = [["e","3"],["t","7"],["t","8"],["d","b"],["p","b"]]
Output: true
Explanation: Replace the first and second 'e' in sub with '3' and 'd' in sub with 'b'.
Now sub = "l33tb" is a substring of s, so we return true.
Input format :
The first line of input contains the string s.
The second line of input contains the substring sub.
The third line of input contains an integer n indicating the number of mappings.
The next n lines of input contains the mappings, where each mapping is given as two space-separated strings representing the characters to be replaced and their replacements.
Output format :
The output prints either "true" if it's possible to replace characters in s to obtain sub using the provided mappings, or "false" otherwise.
Refer to the sample output for the formatting specifications.*/
/*
Code constraints :
1 ≤ sub.length ≤ s.length ≤ 5000
0 ≤ mappings.length ≤ 1000
1 ≤ n ≤ 5
mappings[i].length == 2
oldi != newi
s and sub consist of uppercase and lowercase English letters and digits.
Oldi and newi are either uppercase or lowercase English letters or digits.
Sample test cases :
Input 1 :
fool3e7bar
leet
3
e 3
t 7
t 8
Output 1 :
true
Input 2 :
fooleetbar
f00l
1
o 0
Output 2 :
false
Input 3 :
Fool33tbaR
leetd
5
e 3
t 7*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> arr = {"apple", "banana", "kiwi", "pear", "watermelon"};

    // Sorting array based on length
    std::sort(arr.begin(), arr.end(), [](const std::string &a, const std::string &b) {
        return a.size() < b.size();
    });

    // Print the sorted array
    for (const auto &str : arr) {
        std::cout << str << " ";
    }

    return 0;
}
t 8
