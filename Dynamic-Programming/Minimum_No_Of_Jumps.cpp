//Problem Description : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t,n;
   cin>>t;
   while(t--)
   {
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      int dp[n];
      memset(dp,0,sizeof(dp));
      for(int i=n-1;i>=0;i--)
      {
          if(a[i] == 0)
            dp[i] = -1;
          else if(a[i]>=(n-i-1))
            dp[i] = 1;
          else
          {
              int ans = INT_MAX;
              bool found = false;
              for(int j=1;j<=a[i];j++){
                if(dp[i+j] != -1){
                ans = min(ans,1+dp[i+j]);
                found = true;
                }
              }
              if(found)
              dp[i] = ans;
              else
              dp[i] = -1;
          }
      }
      cout<<dp[0]<<endl;
   }
}
