// C++ program to find maximum length subsequence
// such that adjacent elements have at least
// one common digit
#include <bits/stdc++.h>
using namespace std;

int findSubsequence(int* a,int n)
{
    int cnt[10],dp[10],ans,loc;
    memset(dp,0,sizeof(dp));

    int temp = a[0];
    while(temp>0)
    {
        dp[temp%10]=1;
        temp/=10;
    }

    for(int i=1;i<n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        temp = a[i];
        loc=1;

        while(temp>0)
        {
            cnt[temp%10]=1;
            temp/=10;
        }

        for(int j=0;j<=9;j++)
        {
            if(cnt[j])
            {
                dp[j]++;
                loc=max(loc,dp[j]);
            }
        }

        for(int j=0;j<=9;j++)
        {
            if(cnt[j])
                dp[j]=loc;
        }

        ans = max(loc,ans);
    }

    return ans;
}

int main()
{
	int arr[] = { 1, 12, 44, 29, 33, 96, 89 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findSubsequence(arr, n);

	return 0;
}
