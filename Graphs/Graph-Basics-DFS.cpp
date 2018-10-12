//https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define NO_OF_NODES 5

void addEdge(vector<int> adjList[],int u,int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void dfs(int cur,vector<int> adjList[],vector<bool> &visited)
{
    visited[cur] = true;
    cout<<cur<<" ";
    for(vector<int>::iterator it=adjList[cur].begin();it!=adjList[cur].end();++it)
    {
        if(!visited[*it])
            dfs(*it,adjList,visited);
    }
}

int main()
{
    vector<int> adjList[NO_OF_NODES];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    vector<bool> visited(NO_OF_NODES,false);
    dfs(0,adjList,visited);
}
