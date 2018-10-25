#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(char *a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void printAllPermutations(string s,int start,int end)
{
    if(start == end){
        cout<<s<<endl;
        return;
    }

    for(int i=start;i<=end;i++)
    {
        swap(&s[start],&s[i]);
        printAllPermutations(s,start+1,end);
        swap(&s[i],&s[start]);
    }
}

int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        printAllPermutations(s,0,s.length()-1);
    }
}
