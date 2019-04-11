// A C++ program for merging overlapping intervals
#include<bits/stdc++.h>
using namespace std;

int lpc(string s)
{
    int len = s.length();
    if(len==0) return 0;
    if(len==1) return 1;

    for(int i=0;i<len/2;i++)
    {
        if(s.substr(0,i+1).compare(s.substr(len-i-1,i+1)) == 0)
        {
            return 2+lpc(s.substr(i+1,len-(2*(i+1))));
        }
    }

    return 1;
}

int main()
{
    string s="ghiabcdefhelloadamhelloabcdefghik";
    cout<<lpc(s)<<endl;
    return 0;
}
