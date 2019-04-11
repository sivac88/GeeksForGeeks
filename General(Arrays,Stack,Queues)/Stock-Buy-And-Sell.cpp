//https://www.geeksforgeeks.org/stock-buy-sell/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printStocks(int* arr,int n)
{
    int i=0;
    vector<pair<int,int> > stocks;
    while(i<n-1)
    {
        while(i<(n-1) && arr[i+1]<arr[i])
            i++;
        if(i==(n-1))
            break;
        int purchase = arr[i++];

        while(i<n && arr[i]>arr[i-1])
            i++;

        int sale = arr[i-1];

        stocks.push_back(make_pair(purchase,sale));
    }
    for(vector<pair<int,int> >::iterator it=stocks.begin();it!=stocks.end();it++)
        cout<<"("<<(*it).first<<","<<(*it).second<<")"<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printStocks(arr,n);
}
