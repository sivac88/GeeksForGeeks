//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

bool isValid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

void dfs(int A[MAX][MAX],int i,int j,int N,int M)
{
    A[i][j] = 2;
    
    for(int x=-1;x<=1;x++)
    {
        for(int y=-1;y<=1;y++)
        {
            if(isValid(x+i,y+j,N,M) && A[x+i][y+j]==1)
              dfs(A,x+i,y+j,N,M);
        }
    }
    
}

/*you are required to complete this method*/
int findIslands(int A[MAX][MAX], int N, int M)
{
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]==1)
            {
                dfs(A,i,j,N,M);
                ans++;
            }
        }
    }
    
    return ans;
}