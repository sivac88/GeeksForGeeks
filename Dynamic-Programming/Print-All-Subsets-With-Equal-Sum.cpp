// C++ program to count all subsets with
// given sum.
#include <bits/stdc++.h>
using namespace std;

bool **dp;

void printPaths(int* a,int n,int sum,vector<int>& p)
{
    if(n==0 && sum==0)
    {
        for(int i=0;i<p.size();i++)
            cout<<p[i]<<" ";
        cout<<endl;
        return;
    }

    if(a[n-1]>sum && dp[n-1][sum])
        printPaths(a,n-1,sum,p);
    else
    {
        if(dp[n-1][sum-a[n-1]])
        {
            p.push_back(a[n-1]);
            printPaths(a,n-1,sum-a[n-1],p);
            p.pop_back();
        }
        if(dp[n-1][sum])
        {
            printPaths(a,n-1,sum,p);
        }
    }
}

void printAllSubsets(int* a,int n,int sum)
{
    dp = (bool**)malloc(sizeof(bool*)*(n+1));
    for(int i=0;i<=n;i++){
        dp[i] = (bool*)malloc(sizeof(bool)*(sum+1));
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
                dp[i][j] = dp[i][j-a[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    vector<int> p;
    printPaths(a,n,sum,p);
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);
    return 0;
}
