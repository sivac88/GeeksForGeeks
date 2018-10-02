//Problem Description : https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <iostream>
#include <string.h>
using namespace std;

int x,y,z;

int getAnswer(int n)
{
    if(n<=0 || (n<x && n<y && n<z)) return -1;

    int ans=0,tillNow;

    if(n==x || n==y || n==z) ans=1;

    if((tillNow=getAnswer(n-x))!=-1)
        ans = max(ans,1+tillNow);
    if((tillNow=getAnswer(n-y))!=-1)
        ans = max(ans,1+tillNow);
    if((tillNow=getAnswer(n-z))!=-1)
        ans = max(ans,1+tillNow);

    return ans;
}

int getAnswerDP(int n)
{
    int dp[n+1],ans;
    memset(dp,-1,sizeof(dp));
    if(x<=n)
        dp[x]=1;
    if(y<=n)
        dp[y]=1;
    if(z<=n)
        dp[z]=1;
    for(int i=0;i<=n;i++)
    {
        ans=dp[i];
        if((i-x)>=0 && dp[i-x]!=-1)
            ans=max(ans,1+dp[i-x]);
        if((i-y)>=0 && dp[i-y]!=-1)
            ans=max(ans,1+dp[i-y]);
        if((i-z)>=0 && dp[i-z]!=-1)
            ans=max(ans,1+dp[i-z]);
        dp[i]=ans;
    }
    return dp[n];
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y>>z;
        cout<<getAnswerDP(n)<<endl;
    }
}
