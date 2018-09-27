//Problem Description : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10

int n;
int arr[MAX_N+1][MAX_N+1];
int visited[MAX_N+1][MAX_N+1];
char path[MAX_N*MAX_N];
vector<string> possiblePaths;

bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
        return true;
    return false;
}

void printPossiblePaths(int x,int y,int path_idx)
{
    //Check if it's already visited or if that location is blocked
    if(x==(n-1) && y==(n-1))
    {
        string newPath(path,path_idx);
        possiblePaths.push_back(newPath);
        return;
    }

    //Mark the current piece as visited so that it's not visited again
    visited[x][y] = 1;

    //Go Down ('D')
    if(isValid(x+1,y) && arr[x+1][y]==1 && visited[x+1][y] == 0)
    {
        path[path_idx] = 'D';
        printPossiblePaths(x+1,y,path_idx+1);
    }
    //Go Left('L')
    if(isValid(x,y-1) && arr[x][y-1]==1 && visited[x][y-1] == 0)
    {
        path[path_idx] = 'L';
        printPossiblePaths(x,y-1,path_idx+1);
    }
    //Go Up('U')
    if(isValid(x-1,y) && arr[x-1][y] ==1 && visited[x-1][y] == 0)
    {
        path[path_idx] = 'U';
        printPossiblePaths(x-1,y,path_idx+1);
    }
    //Go Down('R')
    if(isValid(x,y+1) && arr[x][y+1]==1 && visited[x][y+1] == 0)
    {
        path[path_idx] = 'R';
        printPossiblePaths(x,y+1,path_idx+1);
    }

    visited[x][y] = 0;

}

void readInput(int n)
{
    possiblePaths.clear();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            visited[i][j] = 0;
        }
    }
}

void solve()
{
    printPossiblePaths(0,0,0);
    sort(possiblePaths.begin(),possiblePaths.end());
    for(unsigned int i=0;i<possiblePaths.size();i++)
        cout<<possiblePaths[i]<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        readInput(n);
        solve();
    }
}