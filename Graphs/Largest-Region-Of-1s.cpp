// Program to find the length of the largest
// region in boolean 2D-matrix
#include<bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5


bool isValid(int x,int y)
{
    if(x>=0 && x<ROW && y>=0 && y<COL)
        return true;
    return false;
}

int dfs(int x,int y,int M[ROW][COL],bool visited[ROW][COL])
{
    visited[x][y] = true;
    int ans = 1;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0)
                continue;
            if(isValid(x+i,y+j) && !visited[x+i][y+j] && M[x+i][y+j]==1)
            {
                ans+=dfs(x+i,y+j,M,visited);
            }
        }
    }
    return ans;
}

//without visited array
int dfs1(int x,int y,int M[ROW][COL])
{
    M[x][y] = 2;
    int ans = 1;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i==0 && j==0)
                continue;
            if(isValid(x+i,y+j) && M[x+i][y+j]==1)
            {
                ans+=dfs1(x+i,y+j,M);
            }
        }
    }
    //M[x][y]=1; (should not do this because if don't wont to recompute the visited locations
    return ans;
}

int largestRegion(int M[ROW][COL])
{
    int ans = 0;
    bool visited[ROW][COL];
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            visited[i][j] = false;

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(M[i][j]==1 && !visited[i][j])
            {
                //int cur = dfs(i,j,M,visited);
                int cur = dfs1(i,j,M);
                ans = max(ans,cur);
            }
        }
    }
    return ans;
}

// Driver program to test above function
int main()
{
	int M[][COL] = { {0, 0, 1, 1, 0},
					{1, 0, 1, 1, 0},
					{0, 1, 0, 0, 0},
					{0, 0, 0, 0, 1}};

	cout << largestRegion(M);

	return 0;
}
