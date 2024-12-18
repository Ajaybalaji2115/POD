// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,str1;
    getline(cin,str);
    getline(cin,str1);
    int len=str.length();
    int len1=str1.length();
    for(int i=0;i<len;i++)
    {
        string str2="";
        if(i+len1>len)
        break;
        for(int j=i;j<i+len1;j++)
        {
            str2+=str[j];
        }
       
        if(str2==str1)
        {
            cout<<"Found pattern at index "<<i<<endl;
        }
    }
}
/*Janu is tasked with creating a program that solves the Traveling Salesman Problem (TSP). The goal is to find the shortest possible route that visits a set of cities and returns to the starting city. 



You are required to implement a program that takes input regarding the number of cities and the distance matrix between cities and outputs the optimal route and its associated minimum cost.



Note: The diagonal values will be 0, as the distance from a city to itself is 0.

Input format :
The first line of input consists of an integer n, representing the number of cities.

The next n lines contain n space-separated integers each, representing the distance matrix between the cities.

The cell (i, j) represents the distance from city i to city j.

Output format :
The first line of output displays "The Path is: " followed by the path of the route using ---> in between.

The second line displays "Minimum cost is " followed by the total minimum cost associated with the shortest route.



Refer to the sample output for the formatting specifications.

Code constraints :
2 ≤ n ≤ 10

1 ≤ distance ≤ 100

matrix[i][j] = matrix[j][i]

Sample test cases :
Input 1 :
4
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
Output 1 :
The Path is: 1--->3--->2--->4--->1
Minimum cost is 7
Input 2 :
3
0 10 15
10 0 20
15 20 0
Output 2 :
The Path is: 1--->2--->3--->1
Minimum cost is 45
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Function to solve TSP using Dynamic Programming (Held-Karp)
pair<vector<int>, int> tsp(int n, vector<vector<int>> &dist) {
    int full_mask = (1 << n) - 1; // Mask representing all cities visited
    vector<vector<int>> dp(full_mask, vector<int>(n, INF));
    vector<vector<int>> parent(full_mask, vector<int>(n, -1));

    // Base case: start from city 0
    dp[1][0] = 0;

    // Iterate over all subsets of cities
    for (int mask = 1; mask < full_mask; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue; // City `u` is not in the subset

            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue; // City `v` is already visited
                int next_mask = mask | (1 << v);
                int new_cost = dp[mask][u] + dist[u][v];

                if (new_cost < dp[next_mask][v]) {
                    dp[next_mask][v] = new_cost;
                    parent[next_mask][v] = u;
                }
            }
        }
    }

    // Find the minimum cost path that returns to the starting city
    int min_cost = INF, last_city = -1;
    for (int u = 1; u < n; ++u) {
        int cost = dp[full_mask - 1][u] + dist[u][0];
        if (cost < min_cost) {
            min_cost = cost;
            last_city = u;
        }
    }

    // Reconstruct the path
    vector<int> path;
    int mask = full_mask - 1;
    int curr = last_city;
    while (curr != -1) {
        path.push_back(curr);
        int prev = parent[mask][curr];
        mask ^= (1 << curr);
        curr = prev;
    }
    path.push_back(0);
    reverse(path.begin(), path.end());

    return {path, min_cost};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    auto [path, min_cost] = tsp(n, dist);

    cout << "The Path is: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] + 1;
        if (i != path.size() - 1) cout << "--->";
    }
    cout << endl;
    cout << "Minimum cost is " << min_cost << endl;

    return 0;
}
