// C/C++ code for Maximum size square
// sub-matrix with all 1s
#include <bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

int maxSize(bool M[R][C])
{
    int dp[R][C];
    for(int i=0;i<C;i++)
        dp[0][i] = M[0][i];
    for(int i=0;i<R;i++)
        dp[i][0] = M[i][0];

    int ans = 0;

    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(M[i][j])
            {
                dp[i][j]= min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                ans = max(ans,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}

/* Driver function to test above functions */
int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    cout<<maxSize(M);
}
