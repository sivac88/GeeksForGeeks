// A Dynamic programming solution for Word Wrap Problem
#include <bits/stdc++.h>
using namespace std;

int solveWordWrapUtil(int* l,int from,int to,int width)
{
    int cur_width=0;
    for(int i=from;i<=to;i++)
    {
        cur_width+=l[i];
        cur_width+=1;
    }
    cur_width-=1;
    if(cur_width<=width)
        return (width-cur_width)*(width-cur_width);
    int ans = INT_MAX;
    for(int i=from;i<to;i++)
    {
        int till_here_some_lines = solveWordWrapUtil(l,from,i,width);
        int from_next_some_lines = solveWordWrapUtil(l,i+1,to,width);
        ans = min(ans,till_here_some_lines+from_next_some_lines);
    }
    return ans;
}

int solveWordWrapUtilDP(int* l,int n,int m)
{
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i] = m-l[i];
        for(int j=i+1;j<n;j++)
        {
            dp[i][j] = dp[i][j-1]-l[j]-1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(dp[i][j]<0)
                dp[i][j] = INT_MAX;
            else
                dp[i][j]*=dp[i][j];
        }
    }

    int cost[n];

    for(int i=n-1;i>=0;i--)
    {
        cost[i] = dp[i][n-1];
        for(int j=n-1;j>i;j--)
        {
            if(dp[i][j-1]!=INT_MAX && cost[i]>(cost[j]+dp[i][j-1]))
                cost[i] = cost[j]+dp[i][j-1];
        }
    }

    return cost[0];
}

int solveWordWrap(int* l,int n,int m)
{
    //return solveWordWrapUtil(l,0,n-1,m);
    return solveWordWrapUtilDP(l,n,m);
}

// Driver program to test above functions
int main()
{
	int l[] = {3, 2, 2, 5};
	int n = sizeof(l)/sizeof(l[0]);
	int M = 6;
	cout<<solveWordWrap (l, n, M);
	return 0;
}
