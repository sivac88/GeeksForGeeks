//Problem Description : https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 4000
int mat[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n;

int isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
        return 1;
    return 0;
}

int countMaxPathLength(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j] = 1;

    if(isValid(i,j-1) && mat[i][j-1]==1+mat[i][j])
    dp[i][j] = 1+countMaxPathLength(i,j-1);
    else if(isValid(i,j+1) && mat[i][j+1]==1+mat[i][j])
    dp[i][j] = 1+countMaxPathLength(i,j+1);
    else if(isValid(i-1,j) && mat[i-1][j]==1+mat[i][j])
    dp[i][j] = 1+countMaxPathLength(i-1,j);
    else if(isValid(i+1,j) && mat[i+1][j]==1+mat[i][j])
    dp[i][j] = 1+countMaxPathLength(i+1,j);

    return dp[i][j];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cin>>mat[i][j];
               dp[i][j] = -1;
            }
        }

        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               ans=max(ans,countMaxPathLength(i,j));
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
