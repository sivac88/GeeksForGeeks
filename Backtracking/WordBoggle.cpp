//Problem Description : https://practice.geeksforgeeks.org/problems/word-boggle/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 7
#define MAX_M 7

char boggle[MAX_N][MAX_M];
char wordFormed[MAX_N*MAX_N];
bool visited[MAX_N][MAX_M];
int n,m;

void unMark()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j] = false;
}

bool isInvalid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return false;
    return true;
}

bool dfs(int x,int y,int idx,string word)
{
    if(isInvalid(x,y) || boggle[x][y]!=word[idx] || visited[x][y] == true)
        return false;

     visited[x][y] = true;
     wordFormed[idx] = boggle[x][y];

     if(idx+1 == word.length())
     {
         wordFormed[idx+1]= '\0';
         if(word.compare(wordFormed) == 0)
            return true;
         return false;
     }

    if(dfs(x,y-1,idx+1,word) || dfs(x,y+1,idx+1,word) ||
       dfs(x-1,y,idx+1,word) || dfs(x+1,y,idx+1,word) ||
       dfs(x-1,y-1,idx+1,word) || dfs(x+1,y+1,idx+1,word) ||
       dfs(x-1,y+1,idx+1,word) || dfs(x+1,y-1,idx+1,word))
     return true;

    visited[x][y] = false;
    return false;
}

bool wordPresent(string word)
{
    if(word.length() == 0)
        return true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(boggle[i][j]==word[0])
            {
                unMark();
                if(dfs(i,j,0,word))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int t,x,i,j;
    cin>>t;
    while(t--)
    {
        cin>>x;
        string words[x];
        set<string> validStrings;
        for(i=0;i<x;i++)
            cin>>words[i];

        cin>>n>>m;
        for(i=0;i<n;i++)
           for(j=0;j<m;j++)
              cin>>boggle[i][j];


        for(i=0;i<x;i++)
            if(wordPresent(words[i]))
                validStrings.insert(words[i]);

        if(validStrings.size() > 0)
        {
            for(set<string>::iterator it=validStrings.begin();it!=validStrings.end();it++)
            cout<< *it <<" ";
        }
        else
            cout<<"-1";
        cout<<endl;
    }
    return 0;
}
