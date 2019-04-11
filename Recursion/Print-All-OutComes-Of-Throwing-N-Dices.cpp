#include <bits/stdc++.h>
using namespace std;

int cnt=0;

void printAll(char* str,int n)
{
    if(n==0)
    {
        cnt++;
        cout<<str<<endl;
        return;
    }

    for(int i=1;i<=6;i++)
    {
        str[n-1]='0'+i;
        printAll(str,n-1);
    }
}


int main()
{
    int n = 3;
    char str[n+1];
    str[n]='\0';
    printAll(str,n);
    cout<<"\nCount is:"<<cnt;
}
