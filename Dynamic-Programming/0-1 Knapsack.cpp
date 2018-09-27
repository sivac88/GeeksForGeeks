//Problem Description : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int values[MAX_N];
int weights[MAX_N];

int RecursiveKnapsack(int n,int w)
{
    if(n==0 || w==0) return 0;

    if(weights[n-1] <= w)
        return max(values[n-1]+RecursiveKnapsack(n-1,w-weights[n-1]) ,
                   RecursiveKnapsack(n-1,w));

    return RecursiveKnapsack(n-1,w);
}

int knapsackDP(int n,int w)
{
    int dp[n+1][w+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(weights[i-1] <= j)
                dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

   return dp[n][w];
  
}

int main()
{
    int t,n,w;
    cin>>t;
    while(t--)
    {
         cin>>n>>w;
         for(int i=0;i<n;i++)
            cin>>values[i];
         for(int i=0;i<n;i++)
            cin>>weights[i];
         cout<<knapsackDP(n,w)<<endl;
    }
}
