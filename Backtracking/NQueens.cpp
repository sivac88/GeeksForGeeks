//Problem Description : https://practice.geeksforgeeks.org/problems/n-queen-problem/0
#include <iostream>
using namespace std;

#define MAX_N 10
#define SET 1
#define UN_SET 0

int n;
bool solutionFound;

int chessboard[MAX_N][MAX_N];
int ans[MAX_N];


void printSolution()
{
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<ans[i]+1<<" ";
    cout<<"] ";
    return;
}

void markAllPaths(int row,int column,int fill_value)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==row || j==column || abs(i-row)==abs(j-column))
            {
                if(fill_value == SET)
                    chessboard[i][j]++;
                else
                    chessboard[i][j]--;
            }
        }
    }
}

void solveNQueens(int column)
{
    //Solution Found
    if(column==n)
    {
        solutionFound = true;
        printSolution();
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(chessboard[i][column] == 0)
        {
            markAllPaths(i,column,SET);
            ans[column] = i;
            solveNQueens(column+1);
            markAllPaths(i,column,UN_SET);
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solutionFound = false;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            chessboard[i][j] = 0;
        solveNQueens(0);
        if(!solutionFound)
        cout<<"-1";
        cout<<endl;
    }
}
