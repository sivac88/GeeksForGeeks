// C++ program to find Minimum steps
// to reach any of the boundary
// edges of a matrix
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

bool isBoundary(int x,int y)
{
    if(x==0 || x==(R-1) || y==0 || y==(C-1))
        return true;
    return false;
}

bool isValid(int x,int y)
{
    if(x>=0 && x<R && y>=0 && y<C)
        return true;
    return false;
}

int bfs(int mat[R][C],int x,int y)
{
    if(isBoundary(x,y))
        return 0;

    queue<pair<int,pair<int,int> > > q;

    q.push({0,{x,y}});

    while(!q.empty())
    {
        pair<int,pair<int,int> > p = q.front();
        q.pop();

        int cx = p.second.first;
        int cy = p.second.second;

        if(isBoundary(cx,cy))
            return p.first;

        int rows[] = {0,0,-1,1};
        int columns[] = {-1,1,0,0};

        for(int i=0;i<4;i++)
        {
            int nx=cx+rows[i];
            int ny=cy+columns[i];
            if(isValid(nx,ny) && mat[nx][ny]==0)
            {
                mat[nx][ny] = 1;
                q.push({p.first+1,{nx,ny}});
            }
        }
    }
    return -1;
}

int findMinSteps(int mat[R][C],int r,int c)
{
    int flag = 0,i,j;
    for( i=0;i<r;i++)
    {
        for( j=0;j<c;j++)
        {
            if(mat[i][j]==2)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }

    return bfs(mat,i,j);
}

// Driver Code
int main()
{
	int mat[R][C] = { { 1, 1, 1, 0, 1 },
					{ 1, 0, 2, 0, 1 },
					{ 0, 0, 1, 0, 1 },
					{ 1, 0, 1, 1, 0 } };

	cout << findMinSteps(mat, R, C);
}
