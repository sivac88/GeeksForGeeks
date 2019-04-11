// C++ program to print distinct subset sums of
// a given array.
#include<bits/stdc++.h>
using namespace std;

void printDistSumUtil(int* a,int n,int cur_sum,set<int>& s)
{
    if(n==0)
    {
        if(s.find(cur_sum)==s.end())
            s.insert(cur_sum);
        return;
    }

    printDistSumUtil(a,n-1,cur_sum+a[n-1],s);
    printDistSumUtil(a,n-1,cur_sum,s);
}

void printDistSumDP(int* a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;
    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int i=1;i<=n;i++)
    {
        dp[i][a[i-1]]=true;
        for(int j=1;j<=sum;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][j] = true;
                dp[i][j+a[i-1]]=true;
            }
        }
    }

    for(int i=0;i<=sum;i++)
    {
        if(dp[n][i])
            cout<<i<<" ";
    }
}

void printDistSum(int* a,int n)
{
    /*
        set<int> s;
        printDistSumUtil(a,n,0,s);
        for(int val : s)
            cout<<val<<" ";
    */

    printDistSumDP(a,n);

}



// Driver code
int main()
{
	int arr[] = {2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDistSum(arr,n);
	return 0;
}
