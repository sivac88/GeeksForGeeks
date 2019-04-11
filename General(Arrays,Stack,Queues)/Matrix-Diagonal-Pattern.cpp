// C++ program to print matrix in diagonal order
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

void printMatrixDiagonal(int mat[MAX][MAX],int n)
{
    bool isUp = true;
    int i=0,j=0;
    for(int k=0;k<(n*n);)
    {
        if(isUp)
        {
            while(i>=0 && j<n)
            {
                cout<<mat[i][j]<<" ";
                i--,j++;
                k++;
            }

            if(i<0 && j<n)
                i=0;
            if(j==n)
                i+=2,j--;
        }
        else
        {
            while(i<n && j>=0)
            {
                cout<<mat[i][j]<<" ";
                i++,j--;
                k++;
            }

            if(j<0 && i<n)
                j=0;
            if(i==n)
                i--,j+=2;
        }

        isUp = !isUp;
    }
}

int main()
{
    int mat[MAX][MAX] = {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;
    printMatrixDiagonal(mat, n);
    return 0;
}
