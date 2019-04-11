// Program to convert Roman Numerals to Numbers
#include<bits/stdc++.h>
using namespace std;

int value(char s)
{
    if(s=='I')
        return 1;
    if(s=='V')
        return 5;
    if(s=='X')
        return 10;
    if(s=='L')
        return 50;
    if(s=='C')
        return 100;
    if(s=='D')
        return 500;
    if(s=='M')
        return 1000;
}

int romanToDecimal(string s)
{
    int len = s.length();
    int ans = 0;
    for(int i=0;i<len;i++)
    {
        int s1=value(s[i]);
        int s2=-1;
        if(i<(len-1))
            s2=value(s[i+1]);
        if(s2==-1)
            ans+=s1;
        if(s2>s1){
            ans+=s2-s1;
            i++;
        }
        else
            ans+=s1;
    }
    return ans;
}

// Driver Program
int main()
{
	// Considering inputs given are valid
	string str ="MCMIV";
	cout << "Integer form of Roman Numeral is "
		<< romanToDecimal(str) << endl;

	return 0;
}
