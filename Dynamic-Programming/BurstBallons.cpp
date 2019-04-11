#include <bits/stdc++.h>
using namespace std;

int maxBurstValue(int* a,int n)
{
    int dp[n][n];
    for(int len=0;len<n;len++)
    {
        for(int i=0,j=len;j<n;i++,j++)
        {
            dp[i][j] = 0;
            for(int x=i;x<=j;x++)
            {
                int left=0,right=0,left_val=1,right_val=1;
                if(x!=i)
                    left = dp[i][x-1];
                if(x!=j)
                    right = dp[x+1][j];

                if(i!=0)
                    left_val = a[i-1];

                if(j!=(n-1))
                    right_val=a[j+1];

                dp[i][j] = max(dp[i][j],left+right+(a[x]*left_val*right_val));
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    int arr[]={3,1,5,8};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Maximum value obtained by bursting ballons is :"<<maxBurstValue(arr,n)<<endl;
}
