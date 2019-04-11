//Problem Description : https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int lengths[MAX_N];
int price[MAX_N];

int maxCostRec(int n,int len,int sum)
{
     if(n==0) return sum;

     if(lengths[n-1] <= len)
        return max(maxCostRec(n,len-lengths[n-1],sum+price[n-1]),
                   maxCostRec(n-1,len,sum));

     return maxCostRec(n-1,len,sum);
}

int maxCostDP(int n,int len)
{
    int dp[n+1][len+1];

    for(int i=0;i<=len;i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=len;j++)
        {
            if(lengths[i-1] <= j)
                dp[i][j] = max(dp[i-1][j],price[i-1]+dp[i][j-lengths[i-1]]);
            else
                dp[i][j] = dp[i-1][j];

        }
    }

    return dp[n][len];
}

int main()
{
    int t,n,len;
    cin>>t;
    while(t--)
    {
        cin>>n>>len;
        for(int i=0;i<n;i++){
            cin>>lengths[i];
        }
        for(int i=0;i<n;i++){
            cin>>price[i];
        }
        //cout<<maxCostRec(n,len,0)<<endl;
        cout<<maxCostDP(n,len)<<endl;
    }
    return 0;
}


/*

ONE STATE DP (WE DONT HAVE TO STORE THE CURRENT LEN AND N SEPERATELY)

// A Naive recursive solution for Rod cutting problem
#include<bits/stdc++.h>
using namespace std;

int cutRod(int* a,int n)
{
    if(n==0) return 0;
    int ans = -1;
    for(int i=1;i<=n;i++)
        ans = max(ans,cutRod(a,n-i)+a[i-1]);
    return ans;
}

int cutRodDP(int* a,int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        for(int j=1;j<=i;j++)
        {
            dp[i]=max(dp[i],dp[i-j]+a[j-1]);
        }
    }
    return dp[n];
}

int main()
{
	int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Maximum Obtainable Value is %d \n", cutRodDP(arr, size));
	return 0;
}


*/