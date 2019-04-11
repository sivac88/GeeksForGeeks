//https://www.geeksforgeeks.org/reduce-a-number-to-1-by-performing-given-operations/
// CPP program to count minimum
// steps to reduce a number
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int dp[1000];


int countwaysBottomUP(int n)
{
    if(dp[n]!=-1)
        return dp[n];

	if (n == 1)
		return 0;
	else if (n % 2 == 0)
		dp[n] = 1 + countwaysBottomUP(n / 2);
	else
		dp[n] = 1 + min(countwaysBottomUP(n - 1),
					countwaysBottomUP(n + 1));

    return dp[n];
}

int countWaysDP(int n)
{
    int dp1[n+1];

    dp1[1] = 0;

    for(int i=2;i<=n;i++)
    {
        if(i%2 == 0)
            dp1[i]=1+dp1[i/2];
        else
            dp1[i]=1+min(dp1[i-1],1+dp1[(i+1)/2]);
    }
    return dp1[n];
}


// Driver code
int main()
{
	int n = 15;

	memset(dp,-1,sizeof(dp));

	cout << countWaysDP(n)<< "\n";

	return 0;
}
