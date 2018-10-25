//https://practice.geeksforgeeks.org/problems/circle-of-strings/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_CHARS 26

int n;

void dfs(int vertex,vector<int> graph[],vector<bool> &visited)
{
    visited[vertex] = true;
    for(vector<int>::iterator it=graph[vertex].begin();it!=graph[vertex].end();it++)
       if(!visited[*it])
        dfs(*it,graph,visited);
}

bool checkdfs(int vertex,vector<int> graph[],vector<bool> &mark)
{
    vector<bool> visited(MAX_CHARS,false);
    dfs(vertex,graph,visited);

    for(int i=0;i<MAX_CHARS;i++)
    {
        if(mark[i] && !visited[i])
            return false;
    }

    return true;
}

bool findCircle(string s[])
{
    vector<bool> mark(MAX_CHARS,false);
    vector<int> in(MAX_CHARS,0);
    vector<int> out(MAX_CHARS,0);

    vector<int> graph[MAX_CHARS];

    for(int i=0;i<n;i++)
    {
        int f = s[i].front()-'a';
        int l = s[i].back()-'a';

        mark[f]=true,mark[l]=true;

        out[f]++;
        in[l]++;

        graph[f].push_back(l);
    }

    for(int i=0;i<MAX_CHARS;i++)
        if(mark[i] && in[i]!=out[i])
          return false;

    return checkdfs(s[0].front()-'a',graph,mark);
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    string s[n];

	    for(int i=0;i<n;i++)
	      cin>>s[i];

	     if(findCircle(s))
	     cout<<1<<endl;

	     else
	     cout<<0<<endl;
	}
	return 0;
}
