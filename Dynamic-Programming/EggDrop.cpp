//Problem Description : https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
//Useful Video : https://www.youtube.com/watch?v=3hcaVyX00_4
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minNoOfWays(int f,int e)
{
    if(e==0 || f==0) return 0;
    
    if(e==1) return f;
    
    if(f==1) return 1;
    
    int ans,res=INT_MAX;
    for(int i=1;i<=f;i++)
    {
        ans=1+max(minNoOfWays(i-1,e-1),minNoOfWays(f-i,e));
        res=min(res,ans);
    }
    
    return res;
}

#define MAX_EGGS 11
#define MAX_FLOORS 51

int dp1[MAX_FLOORS][MAX_EGGS];

int minNoOfWaysDP1(int f,int e)
{
    if(dp1[f][e]!=-1)
    return dp1[f][e];
    
    if(f==0 || e==0) {
        dp1[f][e] = 0;
        return dp1[f][e];
    }
    
    if(f==1) {
        dp1[f][e] = 1;
        return 1;
    }
    
    if(e==1) 
    {
        dp1[f][e] = f;
        return f;
    }
    
    int ans,res=INT_MAX;
    for(int i=1;i<=f;i++)
    {
        ans = 1+max(minNoOfWaysDP1(i-1,e-1),minNoOfWaysDP1(f-i,e));
        res = min(ans,res);
    }
    
    dp1[f][e] = res;
    
    return dp1[f][e];
}

int minNoOfWaysDP2(int f,int e)
{
    int dp[f+1][e+1];
    
    for(int i=0;i<=e;i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
        
    for(int i=0;i<=f;i++)
    {
        dp[i][0] = 0;
        dp[i][1] = i;
    }
    
    for(int i=2;i<=f;i++)
    {
        for(int j=2;j<=e;j++)
        {
            dp[i][j] = INT_MAX;
            for(int k=1;k<=i;k++)
            {
                int ans = 1+max(dp[k-1][j-1],dp[i-k][j]);
                dp[i][j] = min(dp[i][j],ans);
            }
        }
    }
    
    return dp[f][e];
}


int main() {
	int t,floors,eggs;
	cin>>t;
	while(t--)
	{
	    cin>>eggs>>floors;
	    //memset(dp1,-1,sizeof(dp1[0][0])*MAX_EGGS*MAX_FLOORS);
	    cout<<minNoOfWaysDP2(floors,eggs)<<endl;
	}
	return 0;
}