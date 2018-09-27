//Problem Description : https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <iostream>
using namespace std;

int recursive_lcs(string str1,int idx1,string str2,int idx2)
{
    if(idx1 < 0 || idx2 < 0) return 0;

    if(str1[idx1] == str2[idx2])
        return 1+recursive_lcs(str1,idx1-1,str2,idx2-1);

    return max(recursive_lcs(str1,idx1,str2,idx2-1),recursive_lcs(str1,idx1-1,str2,idx2));
}

int lcs(string str1,int len1,string str2,int len2)
{
    int dp[len1+1][len2+1];
    int i,j;
    for(i=0;i<len1;i++)
        dp[i][0] = 0;
    for(i=0;i<len2;i++)
        dp[0][i] = 0;

    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i] == str2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[len1][len2];
}

int main()
{
    int t,len1,len2;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>len1>>len2;
        cin>>str1>>str2;
        //cout<<recursive_lcs(str1,len1-1,str2,len2-1)<<endl;
        cout<<lcs(str1,len1,str2,len2)<<endl;
    }
}
