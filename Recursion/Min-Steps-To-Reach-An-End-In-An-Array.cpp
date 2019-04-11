#include<bits/stdc++.h>
using namespace std;

int minSteps(int* a,int n)
{
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            if((j+i)<n && dp[j+i]>(1+dp[i]))
                dp[j+i]=1+dp[i];
        }
    }
    return dp[n-1];
}

int minStepsApp2(int* a,int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if((i<=(j+a[j])) && dp[j]!=INT_MAX)
                dp[i]=min(dp[i],dp[j]+1);
        }
    }
    return dp[n-1];
}

int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(arr)/sizeof(int);
    cout<<minStepsApp2(arr,n);
}
