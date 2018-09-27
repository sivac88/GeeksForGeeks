//Problem Description : https://practice.geeksforgeeks.org/problems/coin-change/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 301

int a[MAX_N];
int dp[MAX_N][MAX_N];


int coinChangeRecursive(int m,int n)
{
    if(n==0) return 1;
    if(m==0) return 0;
    if(a[m-1] <= n)
        return coinChangeRecursive(m,n-a[m-1]) + coinChangeRecursive(m-1,n);
    else
        return coinChangeRecursive(m-1,n);
}

int coinChangeDPUpDown(int m,int n)
{
    if(dp[m][n]!=-1) return dp[m][n];

    if(n==0)
    {
        dp[m][n] = 1;
        return dp[m][n];
    }
    if(m==0)
    {
        dp[m][n] = 0;
        return dp[m][n];
    }

    if(a[m-1] <= n)
        dp[m][n]=coinChangeRecursive(m,n-a[m-1]) + coinChangeRecursive(m-1,n);
    else
        dp[m][n]=coinChangeRecursive(m-1,n);

    return dp[m][n];
}

int coinChangeDPBottomUp(int m,int n)
{
    int dp1[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0)
               dp1[i][j] = 1;
            else if(i==0)
                dp1[i][j] = 0;
            else if(a[i-1] <= j)
                dp1[i][j] = dp1[i][j-a[i-1]] + dp1[i-1][j];
            else
                dp1[i][j] = dp1[i-1][j];

        }
    }

    return dp1[m][n];
}

void initialize()
{
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<MAX_N;j++)
           dp[i][j] = -1;
}

int main()
{
   int t,m,n;
   cin>>t;
   while(t--)
   {
       //initialize();
       cin>>m;
       for(int i=0;i<m;i++)
        cin>>a[i];
       cin>>n;
       cout<<coinChangeDPBottomUp(m,n)<<endl;
   }
}