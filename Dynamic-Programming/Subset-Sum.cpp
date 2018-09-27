//Problem Description : https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101

int a[MAX_N];

bool subsetSum1(int n,int total,int sum1,int sum2)
{
    if(sum1==sum2 && sum1+sum2 == total)
        return true;
    if(n==0)
        return false;

    return subsetSum1(n-1,total,sum1+a[n-1],sum2) || subsetSum1(n-1,total,sum1,sum2+a[n-1]);
}

bool IsSumPresentDP(int n,int sum)
{
    int dp[2][sum+1],currentRow=1;

    for(int i=0;i<=n;i++)
    {
        currentRow = 1-currentRow;
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[currentRow][j] = true;
            else if(i==0)
                dp[currentRow][j] = false;
            else if(a[i-1] <= j)
                dp[currentRow][j] = dp[1-currentRow][j-a[i-1]] || dp[1-currentRow][j];
            else
                dp[currentRow][j] = dp[1-currentRow][j];
        }
    }
    return dp[currentRow][sum];
}

bool IsSumPresentRec(int n,int sum)
{
    if(sum==0) return true;
    if(n==0) return false;

    if(a[n-1] <= sum)
        return IsSumPresentRec(n-1,sum-a[n-1]) || IsSumPresentRec(n-1,sum);

    return IsSumPresentRec(n-1,sum);
}

bool subsetSum2(int n,int total)
{
    if(total%2 != 0) return false;

    return IsSumPresentDP(n,total/2);
}



int main()
{
    int t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(subsetSum2(n,sum))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
