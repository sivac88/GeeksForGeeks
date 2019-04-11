#include <bits/stdc++.h>
using namespace std;

void merge(int* a,int n1,int* b,int n2)
{
    int i,j;
    for(i=n2-1;i>=0;i--)
    {
        int last = a[n1-1];
        for(j=n1-2;j>=0;j--)
        {
            if(a[j]>b[i])
                a[j+1]=a[j];
            else
                break;
        }

        if(a[j+1]>b[i])
        {
            a[j+1]=b[i];
            b[i]=last;
        }
    }
}

int main()
{
    int a1[]={1,5,9,10,15,20};
    int a2[]={2,3,8,13};
    int n1 = sizeof(a1)/sizeof(int);
    int n2 = sizeof(a2)/sizeof(int);
    merge(a1,n1,a2,n2);
    for(int i=0;i<n1;i++)
        cout<<a1[i]<< " ";
    for(int i=0;i<n2;i++)
        cout<<a2[i]<<" ";
    return 0;
}
