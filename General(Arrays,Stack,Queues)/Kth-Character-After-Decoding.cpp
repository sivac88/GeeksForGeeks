// C++ implementation of the approach
#include <cstdlib>
#include <iostream>
using namespace std;

char findKthChar(string s,int k)
{
    int len = s.length();
    int i=0,len_till_now=0,next_length;
    while(i<len)
    {
        while(i<len && (s[i]>='a' && s[i]<='z'))
        {
            len_till_now++;
            if(len_till_now==k)
                return s[i];
            i++;
        }

        if(i==len) return -1;

        int num = 0;
        while(i<len && (s[i]>='0' && s[i]<='9'))
        {
            num=num*10+(s[i]-'0');
            i++;
        }

        next_length = len_till_now*num;

        if(k<=next_length)
        {
            k=k%len_till_now;

            if(k==0)
                k=len_till_now;

            return findKthChar(s,k);
        }
        else
        {
            len_till_now = next_length;
        }
    }

    return -1;
}

// Driver code
int main()
{
	string s = "ab2c3";
	int k = 5;

	cout << findKthChar(s, k);

	return 0;
}
