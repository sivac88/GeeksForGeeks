//Problem Description : https://practice.geeksforgeeks.org/problems/josephus-problem/1
#include <iostream>
using namespace std;


int josephus(int n,int k)
{
    if(n==1) return 1;

    return (josephus(n-1,k)+(k-1))%n + 1;
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<josephus(n,k)<<endl;
    }
}
