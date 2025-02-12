/*Single File Programming Question
Problem Statement



Given a directed graph represented using an adjacency list, the task is to find the length of the shortest cycle in the graph. A cycle is a path that starts and ends at the same vertex, and the length of the cycle is defined as the sum of the weights of all the edges in the cycle. If no cycle is found in the graph, output a message indicating that no cycle exists.



Example

Input 

4

4

0 1 2

1 2 3

2 0 4

3 1 5

Output 

Length of the shortest cycle: 9



Explanation

After exploring all starting vertices, the code checks for cycles by examining the distances. If an edge leads back to the starting vertex, it means there is a cycle. In this case, edge 1 (vertex 1) leads back to the starting vertex 0. The code calculates the length of the cycle by adding the distances of the vertices along the cycle: 2 (0 -> 1) + 3 (1 -> 2) + 4 (2 -> 0) = 9.



Therefore, the output is "Length of the shortest cycle: 9".



Input 2

3

2

0 1 2

1 2 3

Output 2

No cycle was found in the graph.



Explanation

After exploring all starting vertices, the code checks for cycles by examining the distances. If an edge leads back to the starting vertex, it means there is a cycle. However, in this case, there are no edges that lead back to the starting vertex. Hence, there is no cycle in the graph.

Therefore, the output is "No cycle found in the graph."

Input format :
The first line of input consists of an integer v, representing the number of vertices in the graph.

The second line of input consists of an integer e, representing number of edges in the graph.

The next edges lines each contain three integers: source, destination, and weight, representing a directed edge from source to destination with the given weight.

Output format :
If a cycle exists, print "Length of the shortest cycle: X", where X is the length of the shortest cycle.

If no cycle exists, print "No cycle found in the graph".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ v ≤ 5

1 ≤ edges ≤ 7

0 ≤ S, D < V

1 ≤ W ≤ 5

Weights are positive integers.

Sample test cases :
Input 1 :
4
4
0 1 2
1 2 3
2 0 4
3 1 5
Output 1 :
Length of the shortest cycle: 9
Input 2 :
3
2
0 1 2
1 2 3
Output 2 :
No cycle found in the graph.
Input 3 :
3
3
0 1 2
1 2 3
2 0 4
Output 3 :
Length of the shortest cycle: 9
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();
int findShortestCycle(int v,vector<vector<pair<int,int>>>&adj)
{
    int shortestCycle=INF;
    for(int start=0;start<v;start++)
    {
        vector<int>dist(v,INF);
        vector<int>parent(v,-1);
        queue<int>q;
        dist[start]=0;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto& edge:adj[node])
            {
                int neighbor=edge.first;
                int weight=edge.second;
                if(dist[neighbor]==INF)
                {
                    dist[neighbor]=dist[node]+weight;
                    parent[neighbor]=node;
                    q.push(neighbor);
                }
                else if(parent[node]!=neighbor)
                {
                    shortestCycle=min(shortestCycle,dist[node]+weight+dist[neighbor]);
                }
            }
        }
    }
    return (shortestCycle == INF)? -1: shortestCycle;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);
    for(int i=0;i<e;i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adj[src].push_back({dest,weight});
    }
    int result=findShortestCycle(v,adj);
    if(result==-1)
    cout<<"No cycle found in the graph.";
    else
    cout<<"Length of the shortest cycle: "<<result;
}
