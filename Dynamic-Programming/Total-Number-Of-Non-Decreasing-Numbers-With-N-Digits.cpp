//https://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/
// C++ program to count non-decreasing number with n digits
#include<bits/stdc++.h>
using namespace std;

int countUtil(int n,int prev)
{
    if(n==0) return 1;
    int ans = 0;
    for(int i=0;i<=prev;i++)
    {
        ans+=countUtil(n-1,i);
    }
    return ans;
}

int countUtilDP(int n)
{
    int dp[n+1][10];

    for(int i=0;i<=10;i++)
        dp[0][i] = 1;
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            dp[i][j] = 0;
            for(int k=0;k<=j;k++)
                dp[i][j] += dp[i-1][k];
        }
    }

    return dp[n][9];

}

int countNonDecreasing(int n)
{
    //return countUtil(n,9);
    return countUtilDP(n);
}

// Driver program
int main()
{
	int n = 3;
	cout << countNonDecreasing(n);
	return 0;
}
