 vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Max heap to get the largest available character
    priority_queue<pair<char, int>> maxHeap;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            maxHeap.push({char('a' + i), freq[i]});
        }
    }

    string result;
    while (!maxHeap.empty()) {
        // Get the largest available character
        auto [currentChar, count] = maxHeap.top();
        maxHeap.pop();

        // Check if the current character can be added up to repeatLimit times
        int useCount = min(count, repeatLimit);
        result.append(useCount, currentChar);
        count -= useCount;

        // If the current character still has remaining count
        if (count > 0) {
            if (maxHeap.empty()) {
                // If no other character is available, we cannot satisfy the condition
                break;
            }

            // Get the second largest character
            auto [nextChar, nextCount] = maxHeap.top();
            maxHeap.pop();

            // Add one instance of the second largest character
            result.push_back(nextChar);
            nextCount--;

            // Push the second largest character back if it still has a count
            if (nextCount > 0) {
                maxHeap.push({nextChar, nextCount});
            }

            // Push the current character back to the heap with its remaining count
            maxHeap.push({currentChar, count});
        }
    }

    return result;
/*Given an NxN chessboard where N is 8 and a Knight at position (x,y). The Knight has to take exactly K steps, where at each step it chooses any of the 8 directions uniformly at random. What is the probability that the Knight remains in the chessboard after taking K steps, with the condition that it can’t enter the board again once it leaves it?



Write a program for the same.



The Knight moves according to the following rules, defined by the changes in the x and y coordinates:

dx = {1, 2, 2, 1, -1, -2, -2, -1};

dy = {2, 1, -1, -2, -2, -1, 1, 2};



Note: Use Dynamic Programming

﻿

Example:



Let's take: an 8x8 chessboard,

initial position of the knight : (0, 0), number of steps: 1

At each step, the Knight has 8 different positions to choose from. 

If it starts from (0, 0), after taking one step it will lie inside the

board only at 2 out of 8 positions and will lie outside at other positions.



So, the probability is 2/8 = 0.25

Input format :
The input consists of the value of K, which represents the number of steps.

Output format :
The output prints the probability that the Knight remains on the chessboard after taking exactly K steps, rounded to four decimal places.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ K ≤ 10

Sample test cases :
Input 1 :
1
Output 1 :
0.2500
Input 2 :
4
Output 2 :
0.0986
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double knightProbability(int N, int K, int start_x, int start_y) {
    vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};

    // Create a 3D DP table dp[k][x][y] for k steps at position (x, y)
    vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0.0)));

    // Base case: At step 0, the knight is at the starting position
    dp[0][start_x][start_y] = 1.0;

    // Fill the DP table for each step
    for (int k = 1; k <= K; ++k) {
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                for (int move = 0; move < 8; ++move) {
                    int prev_x = x - dx[move], prev_y = y - dy[move];
                    if (prev_x >= 0 && prev_x < N && prev_y >= 0 && prev_y < N) {
                        dp[k][x][y] += dp[k - 1][prev_x][prev_y] / 8.0;
                    }
                }
            }
        }
    }

    // Sum the probabilities of remaining on the board after K steps
    double probability = 0.0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            probability += dp[K][x][y];
        }
    }
    return probability;
}

int main() {
    int K;
    cin >> K;
    int N = 8; // Chessboard size
    int start_x = 0, start_y = 0; // Initial position of the knight

    cout << fixed << setprecision(4) << knightProbability(N, K, start_x, start_y) << endl;
    return 0;
}
