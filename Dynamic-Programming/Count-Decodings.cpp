// A Dynamic Programming based C++ implementation to count decodings
#include <iostream>
#include <cstring>
using namespace std;

int countDecoding(char *digits,int n,int pos)
{
    if(pos==n) return 0;
    if((n-pos) == 1)
    {
        if(digits[pos]=='0') return 0;
        return 1;
    }

    if(digits[pos]=='1' && (digits[pos+1]>='0' && digits[pos+1]<='9'))
        return countDecoding(digits,n,pos+1)+countDecoding(digits,n,pos+2);

    if(digits[pos]=='2' && (digits[pos+1]>='0' && digits[pos+1]<='6'))
        return countDecoding(digits,n,pos+1)+countDecoding(digits,n,pos+2);

    return countDecoding(digits,n,pos+1);

}

int countDecodingEasy(char* digits,int n)
{
    if(n<=1) return 1;

    int count = 0;
    if(digits[n-1]>'0')
        count+=countDecodingEasy(digits,n-1);

    if(digits[n-2]=='1' || (digits[n-2]=='2' && digits[n-1]<='6'))
        count+=countDecodingEasy(digits,n-2);

    return count;
}

int countDecodingDP(char* digits,int n)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(digits[i-1]>='0')
            dp[i]+=dp[i-1];
        if(digits[i-2]=='1' || (digits[i-2]=='2' && digits[i-2]<='6'))
            dp[i]+=dp[i-2];
    }
    return dp[n];
}

// Driver program to test above function
int main()
{
	char digits[] = "1234";
	int n = strlen(digits);
	cout << "Count is " << countDecodingDP(digits, n);
	return 0;
}
