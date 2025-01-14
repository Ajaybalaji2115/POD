/*Single File Programming Question
Problem Statement



A target word and a list of words are provided to you. The objective is to identify the word from the list closest to the target word in Levenshtein distance. The least amount of insertion, deletion, or substitution needed to change one word into another is the Levenshtein distance.



Example1



Input:

banana, cherry, orange, pineapple

penapple



Output:

apple



Explanation:

The task is to find the word from the given list with the smallest Levenshtein distance with the target word "penapple".

To calculate the Levenshtein distance, the algorithm compares each word from the list with the target word and determines the number of operations (insertion, deletion, or substitution) required to transform the target word into each word from the list.

In this case, we compare "penapple" with each word in the list:



"banana": To transform "penapple" into "banana", we need to substitute 'p' with 'b', insert 'n' at the second position, and delete 'e' and 'l'. This requires 4 operations.
"cherry": To transform "penapple" into "cherry", we need to substitute 'p' with 'c', insert 'h' at the second position, and delete 'n' and 'a'. This requires 4 operations.
"orange": To transform "penapple" into "orange", we need to substitute 'p' with 'o', insert 'r' at the second position, and delete 'e', 'n', and 'a'. This requires 5 operations.
"pineapple": To transform "penapple" into "pineapple", we need to substitute 'p' with 'p', insert 'i' at the second position, and delete 'e' and 'n'. This requires 3 operations.
Among these words, "pineapple" has the smallest Levenshtein distance of 3, which is the fewest number of operations required to transform "penapple" into "pineapple".

Input format :
The first line of the input consists of a list of words that should be entered as a comma-separated string.

The second line of the input consists of the target word should be entered as a single word.

Output format :
The output displays the word from the given list with the smallest Levenshtein distance from the target word.

Code constraints :
The length of each word in the list should not exceed the maximum limit allowed by the programming language or system.

The number of words in the list should be reasonable and not excessively large.

The input words can contain any printable characters.

The solution should be efficient and handle the given input size in a reasonable amount of time.

Sample test cases :
Input 1 :
banana, cherry, orange, pineapple
penapple
Output 1 :
 pineapple
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
#include <bits/stdc++.h>
using namespace std;

// Function to calculate Levenshtein distance
int levenshteinDistance(const string &s1, const string &s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[n][m];
}

int main() {
    // Input
    string input, target;
    getline(cin, input);  // Read the list of words
    cin >> target;        // Read the target word

    // Split the input string into words
    stringstream ss(input);
    string word;
    vector<string> words;
    while (getline(ss, word, ',')) {
        words.push_back(word);
    }
    // Find the word with the smallest Levenshtein distance
    string closestWord;
    int minDistance = INT_MAX;

    for (const string &w : words) {
        int distance = levenshteinDistance(w, target);
        if (distance < minDistance) {
            minDistance = distance;
            closestWord = w;
        }
    }

    // Output the result
    cout << closestWord << endl;
    return 0;
}
