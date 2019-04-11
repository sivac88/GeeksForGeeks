#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int matrixChainMulti(vector<pair<int,int> > &v,int a,int b)
{
  if(a==b) return 0;
  int ans = INT_MAX;
  for(int i=a;i<b;i++)
  {
       int cur = matrixChainMulti(v,a,i) +
                 matrixChainMulti(v,i+1,b) +
                 (v[a].first)*(v[i].second)*(v[b].second);

       ans = min(cur,ans);
  }
  return ans;
}

/*  This Method fails for the example used in main
 * int matrixChainMultiDP(vector<pair<int,int> > &v)
 * {
 *     int n = v.size();
 *     int dp[n][n];
 *     for(int i=0;i<n;i++)
 *         dp[i][i] = 0;
 *     for(int len=2;len<=n;len++)
 *     {
 *         for(int i=0;i<n-len+1;i++)
 *         {
 *              dp[i][i+len-1] = min(dp[i][i+len-2] + (v[i].first)*(v[i+len-1].first)*(v[i+len-1].second),
 *                                   dp[i+1][i+len-1] + (v[i].first)*(v[i].second)*(v[i+len-1].second));
 *         }
 *     }
 *     return dp[0][n-1];
 * }
 */


int matrixChainMultiDP(vector<pair<int,int> > &v)
{
    int n = v.size();
    int dp[n][n],ans;
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
             int j = i+len-1;
             dp[i][j] = INT_MAX;
             for(int k=i;k<j;k++)
             {
                   ans = dp[i][k] + dp[k+1][j] + (v[i].first)*(v[k].second)*(v[j].second);
                   dp[i][j] = min(dp[i][j],ans);
             }
        }
    }
    return dp[0][n-1];
}

int main()
{
    vector<pair<int,int> > v;
    v.push_back(make_pair(2,40));
    v.push_back(make_pair(40,2));
    v.push_back(make_pair(2,40));
    v.push_back(make_pair(40,5));
    cout<<"Minimum number of operations: " << matrixChainMultiDP(v);
    return 0;
}
