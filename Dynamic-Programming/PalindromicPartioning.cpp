// Dynamic Programming Solution for Palindrome Partitioning Problem
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(char* str,int i,int j)
{
    while(i<=j)
    {
        if(str[i]!=str[j])
            return false;
        i++,j--;
    }
    return true;
}

int minPalUtil(char* str,int n)
{
    if(n<0) return -1;

    int ans = INT_MAX,cur;

    for(int i=n;i>=0;i--)
    {
        if(isPalindrome(str,i,n))
        {
            cur=1+minPalUtil(str,i-1);
            ans = min(ans,cur);
        }
    }

    return ans;
}

int minPalUtilDP(char* str,int len)
{
    bool pal[len][len];
    for(int gap=0;gap<len;gap++)
    {
        for(int i=0,j=gap;j<len;i++,j++)
        {
            if(gap==0)
                pal[i][j] = true;
            else if(gap==1)
            {
                if(str[i]==str[j])
                    pal[i][j] = true;
                else
                    pal[i][j] = false;
            }
            else
            {
                if(str[i]==str[j] && pal[i+1][j-1])
                    pal[i][j] = true;
                else
                    pal[i][j] = false;
            }
        }
    }

    int dp[len+1];
    dp[0] = -1;
    for(int i=1;i<=len;i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(pal[j][i-1])
                dp[i] = min(dp[i],1+dp[j]);
        }
    }

    return dp[len];
}

int minPalPartion(char *str)
{
    int len = strlen(str);
    //return minPalUtil(str,len-1);
    return minPalUtilDP(str,len);
}

// Driver program to test above function
int main()
{
char str[] = "ababbbabbababa";
printf("Min cuts needed for Palindrome Partitioning is %d",
        minPalPartion(str));
return 0;
}
