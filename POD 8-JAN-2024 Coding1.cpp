/*Single File Programming Question
Problem Statement



You are given a set of cities and the cost of connecting each pair of cities. Your task is to find the minimum cost to connect all the cities using Prim's Algorithm and the minimum spanning tree.



Example



Input: 

5

6

0 1 4

0 2 3

1 2 2

1 3 1

2 3 4

3 4 2

Output: 

8

Explanation:

The minimum spanning tree for this input is as follows:

City 0 is connected to City 2 at a cost of 3.

City 2 is connected to City 1 at a cost of 2.

City 1 is connected to City 3 at a cost of 1.

City 3 is connected to City 4 at a cost of 2.



The total cost of these connections is 3 + 2 + 1 +2 = 8, which is printed as the output.

Input format :
The first line of input contains an integer numCities, representing the number of cities (vertices)

The second line contains an integer numConnections, representing the number of connections (edges) between the cities.

The next numConnections lines contain three space-separated integers: source, destination, and cost, representing a connection between a city's source and destination with the given cost.

Output format :
The output prints the minimum cost required to connect all the cities.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ numCities ≤ 105

Sample test cases :
Input 1 :
5
6
0 1 4
0 2 3
1 2 2
1 3 1
2 3 4
3 4 2
Output 1 :
8
Input 2 :
4
5
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
Output 2 :
7
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int vertex,weight;
    Edge(int v,int w):vertex(v),weight(w){}
};
struct Compare
{
    bool operator()(Edge const& a,Edge const& b)
    {
        return a.weight>b.weight;
    }
};
int primMST(int numCities,vector<pair<int,int>>adj[])
{
    priority_queue<Edge,vector<Edge>,Compare>pq;
    vector<bool>visited(numCities,false);
    int mstCost=0;
    int edgesIncluded=0;
    pq.push(Edge(0,0));
    while(!pq.empty() && edgesIncluded<numCities)
    {
        Edge current=pq.top();
        pq.pop();
        int vertex=current.vertex;
        int weight=current.weight;
        if(visited[vertex])
        continue;
        visited[vertex]=true;
        mstCost+=weight;
        edgesIncluded++;
        for(auto neighbor:adj[vertex])
        {
            if(!visited[neighbor.first])
            {
                pq.push(Edge(neighbor.first,neighbor.second));
            }
        }
    }
    return mstCost;
}
int main()
{
    int numCities,numConnections;
    cin>>numCities>>numConnections;
    vector<pair<int,int>>adj[numCities];
    for(int i=0;i<numConnections;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    int result=primMST(numCities,adj);
    cout<<result<<endl;
}
