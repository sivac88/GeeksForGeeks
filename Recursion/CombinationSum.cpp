// Problem Description : https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int n;
int res[13];
bool atleastOne;

void total(int* a,int i,int ri,int b,int sum)
{
    if(i==n) return;


    if(a[i] + sum > b)
        return;

    if(a[i] + sum == b)
    {
        atleastOne = true;
        res[ri] = a[i];
        cout<<"(";
        for(int j=0;j<=ri;j++)
        {
            cout<<res[j];
            if(j!=ri)
            cout<<" ";
        }
        cout<<")";
        return;
    }

    res[ri] = a[i];
    total(a,i+1,ri+1,b,sum+a[i]);

    while(i<(n-1) && a[i]==a[i+1])
        i++;

    total(a,i+1,ri,b,sum);
}

int main() {
	int t,b,i;
	cin>>t;
	while(t--)
	{
	    atleastOne = false;
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    cin>>b;
	    sort(a,a+n);
	    total(a,0,0,b,0);
	    if(!atleastOne)
	    cout<<"Empty";
	    cout<<endl;
	}
	return 0;
}
