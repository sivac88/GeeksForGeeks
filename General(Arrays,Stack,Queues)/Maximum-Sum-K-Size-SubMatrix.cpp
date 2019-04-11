// An efficient C++ program to find maximum sum
// sub-square matrix
#include <bits/stdc++.h>
using namespace std;

// Size of given matrix
#define N 5

void printMaxSumSub(int mat[][N],int k)
{
    int dp[N-k+1][N],i,j,ans=INT_MIN,ans_i,ans_j;
    for(i=0;i<N;i++)
    {
        int sum = 0,r=0;
        for(j=0;j<k;j++)
            sum+=mat[j][i];
        dp[r++][i] = sum;
        for(;j<N;j++)
        {
            sum+=(mat[j][i]-mat[j-k][i]);
            dp[r++][i]=sum;
        }
    }

    for(i=0;i<N-k+1;i++)
    {
        int sum = 0,r=0;
        for(j=0;j<k;j++)
            sum+=dp[i][j];
        if(sum>ans)
        {
            ans = sum;
            ans_i=i;
            ans_j = r++;
        }
        for(;j<N;j++)
        {
            sum+=dp[i][j]-dp[i][j-k];
            if(sum>ans)
            {
                ans = sum;
                ans_i=i;
                ans_j = r++;
            }
        }
    }

    for(i=ans_i;i<ans_i+k;i++)
    {
        for(j=ans_j;j<ans_j+k;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Driver program to test above function
int main()
{
    int mat[N][N] = {{1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 8, 6, 7, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5},
    };
    int k = 3;

    cout << "Maximum sum 3 x 3 matrix is\n";
    printMaxSumSub(mat, k);

    return 0;
}
