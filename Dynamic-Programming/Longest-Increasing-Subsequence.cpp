//Problem Description : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


int RecursivemaxLength(int* a,int n,int* ans)
{
    if(n==1) return 1;

    int max_till_now = 0,res;

    for(int i=1;i<n;i++)
    {
        res = RecursivemaxLength(a,i,ans);
        if(a[n-1] > a[i-1] && res+1 > max_till_now)
            max_till_now = res + 1;
    }

    if(max_till_now > *ans)
        *ans = max_till_now;

    return max_till_now;
}


void maxLengthDP(int* a,int n,int* ans)
{
    int lis[n];
    for(int i=0;i<n;i++)
        lis[i] = 1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[j]+1 > lis[i])
                lis[i]=lis[j]+1;
        }
    }

    *ans = lis[0];
    for(int i=1;i<n;i++)
        if(lis[i] > *ans)
          *ans = lis[i];
}

int main()
{
    int t,n,res;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res = 0;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        maxLengthDP(a,n,&res);
        cout<<res<<endl;
    }
}
