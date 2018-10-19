//https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 21
#define MAX_M 21

bool mat[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int n,m,fx,fy;

int isValid(int a,int b)
{
    if(a<0 || a>=n || b<0 || b>=m)
    return false;

    return true;
}


int minDistance(int x,int y)
{
    visited[x][y] = true;

    if(!mat[x][y])
      return INT_MAX;

    if(x==fx && y==fy){
      visited[x][y] = false;
      return 0;
    }

    int ans=INT_MAX;

    if(isValid(x+1,y) && !visited[x+1][y])
      ans=min(ans,minDistance(x+1,y));
    if(isValid(x-1,y) && !visited[x-1][y])
      ans=min(ans,minDistance(x-1,y));
    if(isValid(x,y-1) && !visited[x][y-1])
      ans=min(ans,minDistance(x,y-1));
    if(isValid(x,y+1) && !visited[x][y+1])
      ans=min(ans,minDistance(x,y+1));

    visited[x][y] = false;
    return (ans==INT_MAX) ? ans : 1+ans;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	      for(int j=0;j<m;j++){
	        cin>>mat[i][j];
	         visited[i][j] = false;
	      }
        cin>>fx>>fy;
        int ans = minDistance(0,0);
	    if(ans==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
	}
	return 0;
}
