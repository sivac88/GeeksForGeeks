// CPP program for The painter's partition problem
#include <climits>
#include <iostream>
using namespace std;

int sum(int* a,int i,int j)
{
    int val = 0;
    for(int k=i;k<=j;k++)
        val+=a[k];
    return val;
}

int partitionUtil(int* a,int n,int k)
{
    if(n<0 || k==0) return 0;
    if(n==0) return a[0];
    if(k==1) return sum(a,0,n);

    int ans = INT_MAX,cur;
    for(int j=n;j>=0;j--)
    {
        cur = max(partitionUtil(a,j-1,k-1),sum(a,j,n));
        ans = min(ans,cur);
    }

    return ans;
}

int partitionUtilDP(int* a,int n,int k)
{
    int dp[n+1][k+1];
    int cur;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        dp[i][1] = dp[i-1][1]+a[i-1];
    }
    for(int i=1;i<=k;i++)
        dp[1][i] = a[0];

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j] = INT_MAX;
            for(int x=0;x<i;x++)
            {
                cur=max(dp[x][j-1],sum(a,x,i-1));
                dp[i][j]=min(dp[i][j],cur);
            }
        }
    }
    return dp[n][k];
}

int partition(int* a,int n,int k)
{
    //return partitionUtil(a,n-1,k);
    return partitionUtilDP(a,n,k);
}

int main()
{
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << partition(arr, n, k) << endl;

	return 0;
}
