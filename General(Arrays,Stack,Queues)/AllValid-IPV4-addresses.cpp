#include<bits/stdc++.h>
using namespace std;

bool isValid(char* str,int start,int len)
{
    int num = 0;
    for(int i=0,j=start;i<len;i++,j++)
    {
        if(i==0 && str[j]=='0')
            return false;

        num=num*10+(str[j]-'0');
    }

    if(num>=0 && num<=255)
        return true;

    return false;
}


void printSubStrs(char* s,int i,int j,int k,int l)
{
    int x,y=0;
    for(x=0;x<i;x++)
        cout<<s[x];
    cout<<".";
    for(y=0;y<j;x++,y++)
        cout<<s[x];
    cout<<".";
    for(y=0;y<k;x++,y++)
        cout<<s[x];
    cout<<".";
    for(y=0;y<l;x++,y++)
        cout<<s[x];
}


void printAll(char* s,int n)
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int l=1;l<=3;l++)
                {
                    if((i+j+k+l)==n)
                    {
                        if(isValid(s,0,i) && isValid(s,i,j) && isValid(s,i+j,k) && isValid(s,i+j+k,l))
                        {
                            printSubStrs(s,i,j,k,l);
                            cout<<endl;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
   char str[] = "10254411";
   int n = strlen(str);
   printAll(str,n);
}
