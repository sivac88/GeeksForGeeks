// Problem description : https://practice.geeksforgeeks.org/problems/special-keyboard/0
#include <iostream>
using namespace std;

#define MAX_N 75

int dp[MAX_N+1];

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

void preCompute()
{
    int i,j,ans;
    
    for(i=0;i<=6;i++)
    dp[i] = i;
    
    for(i=7;i<=75;i++)
    {
        ans = i;   
        for(j=i-2;j>=2;j--)
        {
            ans = max(ans,dp[j-1]*(i-j));
        }
        dp[i] = ans;
    }
}

int main() {
	int t,n;
	preCompute();
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    if(n>75)
	    cout<<"-1"<<endl;
	    else
	    cout<<dp[n]<<endl;
	}
	return 0;
}