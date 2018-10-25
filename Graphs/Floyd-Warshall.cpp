#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_V 21

int n;
int mat[MAX_V][MAX_V];

void input()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          cin>>mat[i][j];
}

void floydWarshall()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][k]!=INT_MAX &&
                   mat[k][j]!=INT_MAX &&
                   mat[i][j] > mat[i][k] + mat[k][j])
                   
                  mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
}

void printMatrix()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          cout<<mat[i][j]<<" ";
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    input();
	    floydWarshall();
	    printMatrix();
	    cout<<endl;
	}
	return 0;
}