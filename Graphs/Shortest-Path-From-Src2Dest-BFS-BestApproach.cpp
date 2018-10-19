//https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
};

typedef struct point point;

struct queueNode
{
    point p;
    int dist;
};

typedef struct queueNode node;

#define MAX_N 21
#define MAX_M 21

bool mat[MAX_N][MAX_M];

int n,m,fx,fy;

int isValid(int a,int b)
{
    if(a<0 || a>=n || b<0 || b>=m)
    return false;

    return true;
}


int minDistance(int x,int y)
{
    queue<node> q;
    point p = {x,y};
    if(!mat[x][y]) return -1;
    q.push({p,0});
    while(!q.empty())
    {
        node f=q.front();
        q.pop();
        if(f.p.x==fx && f.p.y==fy)
            return f.dist;

       if(isValid((f.p.x)+1,f.p.y) && mat[(f.p.x)+1][f.p.y])
       {
           mat[(f.p.x)+1][f.p.y] = 0;
           q.push({{(f.p.x)+1,f.p.y},f.dist+1});
       }
       if(isValid((f.p.x)-1,f.p.y) && mat[(f.p.x)-1][f.p.y])
       {
           mat[(f.p.x)-1][f.p.y] = 0;
           q.push({{(f.p.x)-1,f.p.y},f.dist+1});
       }
       if(isValid(f.p.x,(f.p.y)+1) && mat[f.p.x][(f.p.y)+1])
       {
           mat[f.p.x][(f.p.y)+1] = 0;
           q.push({{f.p.x,(f.p.y)+1},f.dist+1});
       }
       if(isValid(f.p.x,(f.p.y)-1) && mat[f.p.x][(f.p.y)-1])
       {
           mat[f.p.x][(f.p.y)-1] = 0;
           q.push({{f.p.x,(f.p.y)-1},f.dist+1});
       }
    }
    return -1;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	      for(int j=0;j<m;j++)
	        cin>>mat[i][j];

        cin>>fx>>fy;
        cout<<minDistance(0,0)<<endl;
	}
	return 0;
}
