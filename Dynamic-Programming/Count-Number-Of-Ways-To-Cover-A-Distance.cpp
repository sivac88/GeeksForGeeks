//Problem Description : https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        if((i-1)>=0)
            dp[i] = dp[i-1];
        if((i-2)>=0)
            dp[i]+= dp[i-2];
        if((i-3)>=0)
            dp[i]+= dp[i-3];
     }

    return dp[n];
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<count(n)<<endl;
    }
    return 0;
}
