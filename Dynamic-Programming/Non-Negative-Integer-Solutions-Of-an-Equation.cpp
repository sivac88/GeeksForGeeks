#include <bits/stdc++.h>
using namespace std;

int countAll(int n,int val)
{
    if(n==0 && val==0) return 1;
    if(n==0) return 0;

    int ans = 0;

    for(int i=val;i>=0;i--)
        ans+=countAll(n-1,val-i);

    return ans;
}

int countAllDP(int n,int val)
{
    int dp[n+1][val+1];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=val;j++)
        {
            dp[i][j] = 0;
            for(int k=j;k>=0;k--)
                dp[i][j]+=dp[i-1][j-k];
        }
    }

    return dp[n][val];
}

int main()
{
    int n=5,val=4;
    cout<<countAllDP(n,val);
}
