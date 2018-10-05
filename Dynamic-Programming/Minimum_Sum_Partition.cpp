//Problem Description : https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxDiffRec(int* a,int n,int cur_sum,int sum)
{
    if(n==0)
        return abs(sum-2*cur_sum);

    return min(maxDiffRec(a,n-1,cur_sum+a[n-1],sum),
               maxDiffRec(a,n-1,cur_sum,sum));
}

int maxDiffDP(int *a,int n,int sum)
{
   bool dp[n+1][sum+1];
   for(int i=1;i<=sum;i++)
    dp[0][i] = false;
   for(int i=0;i<=n;i++)
    dp[i][0] = true;

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=sum;j++)
       {
           dp[i][j] = dp[i-1][j];

           if(a[i-1] <= j)
            dp[i][j] |= dp[i-1][j-a[i-1]];
       }
   }

   int diff = INT_MAX;

   for(int i=sum/2;i>=0;i--)
   {
       if(dp[n][i]){
        diff = sum-(2*i);
        break;
       }
   }
   return diff;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        //cout<<maxDiffRec(a,n,0,sum)<<endl;
        cout<<maxDiffDP(a,n,sum)<<endl;
    }
    return 0;
}
