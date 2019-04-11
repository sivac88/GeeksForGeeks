#include <bits/stdc++.h>
using namespace std;

#define V 4

bool isSafe(bool graph[V][V],int cur,int c,int color[])
{
    for(int i=0;i<V;i++)
    {
        if(graph[cur][i] && color[i]==c)
            return false;
    }
    return true;
}

bool dfs(bool graph[V][V],int cur,int m,int color[])
{
    if(cur==V)
        return true;

    for(int c=1;c<=m;c++)
    {
        if(isSafe(graph,cur,c,color))
        {
            color[cur] = c;

            if(dfs(graph,cur+1,m,color))
                return true;

            color[m] = 0;
        }
    }

    return false;
}

void printColours(int* colors)
{
    for(int i=0;i<V;i++)
        cout<<colors[i]<<" ";
}

void graphColoring(bool graph[V][V],int m)
{
    int colour[V] = {0};
    if(dfs(graph,0,m,colour))
        printColours(colour);
    else
        cout<<"Graph cannot be coloured with "<<m<<" colors";
}


// driver program to test above function
int main()
{
	/* Create following graph and test whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0},
	};
	int m = 3; // Number of colors
	graphColoring (graph, m);
	return 0;
}
