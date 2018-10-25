#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int optimalGameStrategy(int* arr,int a,int b)
{
    if(a>b) return 0;
    if(a==b) return arr[a];

    return max(arr[a]+min(optimalGameStrategy(arr,a+2,b),optimalGameStrategy(arr,a+1,b-1)),
               arr[b]+min(optimalGameStrategy(arr,a,b-2),optimalGameStrategy(arr,a+1,b-1)));
}

int optimalGameStrategyDP(int* a,int n)
{
    int dp[n][n];
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j = i+len-1;
            int x = ((i+2) <= j) ? dp[i+2][j] : 0;
            int y = ((i+1) <= (j-1)) ? dp[i+1][j-1] : 0;
            int z = (i <= (j-2)) ? dp[i][j-2] : 0;
            dp[i][j] = max(a[i]+min(x,y),
                           a[j]+min(z,y));
        }
    }
    return dp[0][n-1];
}

int main()
{
   int arr[]={8,15,3,7};
   int n = sizeof(arr)/sizeof(int);
   //cout<<optimalGameStrategy(arr,0,n-1);
   cout<<optimalGameStrategyDP(arr,n);
}
