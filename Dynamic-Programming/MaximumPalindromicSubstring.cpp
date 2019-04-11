// A dynamic programming solution for longest palindr.
// This code is adopted from following link
// http://www.leetcode.com/2011/11/longest-palindromic-substring-part-i.html

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(char* str)
{
    int n = strlen(str);
    int ans = 1;

    bool dp[n][n];
    memset(dp,false,sizeof(dp));

    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            if(gap==0)
                dp[i][j] = true;
            else if(gap==1)
            {
                if(str[i]==str[j]){
                    dp[i][j] = true;
                    ans = max(ans,2);
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                if(str[i]==str[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans = max(ans,j-i+1);
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    return ans;
}

int main()
{
	char str[] = "forgeeksskeegfor";
	printf("\nLength is: %d\n", longestPalSubstr( str ) );
	return 0;
}


/*

RECURSIVE VERSION OF MAX PALINDROMIC SUBSTRING

#include <bits/stdc++.h>
using namespace std;

int maxPalLength(char* s,int i,int j,int cur)
{
    if(i>j) return 0;
    if(i==j) return cur+1;
    int without_including = max(maxPalLength(s,i,j-1,0),maxPalLength(s,i+1,j,0));
    if(s[i]==s[j])
        return max(without_including,maxPalLength(s,i+1,j-1,cur+2));
    return without_including;
}

int maxPalLenDP(char* str)
{
    int len = strlen(str),ans=1;
    bool dp[len][len];
    for(int gap=0;gap<len;gap++)
    {
        for(int i=0,j=gap;j<len;i++,j++)
        {
            if(gap==0)
                dp[i][j] = true;
            else if(gap==1)
            {
                if(str[i]==str[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if(str[i]==str[j] && dp[i+1][j-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }

            if(dp[i][j])
                ans = max(ans,j-i+1);
        }
    }

    return ans;
}

int maxPalLength(char* str)
{
    //return maxPalLength(str,0,strlen(str)-1,0);
    return maxPalLenDP(str);
}

// Driver program to test above function
int main()
{
char str[] = "ababbbabbababa";
cout<<maxPalLength(str);
return 0;
}

*/
