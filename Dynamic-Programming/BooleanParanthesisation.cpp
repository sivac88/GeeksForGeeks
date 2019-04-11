#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int dp[100][100][2];

int countParenthesisUtil(char* str,int i,int j,bool isTrue)
{
    if(i>j) return 0;

    if(i==j)
    {
        if(isTrue)
        {
            if(str[i]=='T') return 1;
            return 0;
        }
        else
        {
            if(str[i]=='F') return 1;
            return 0;
        }
    }

    if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];

    int ans = 0;

    for(int k=i+1;k<j;k+=2)
    {
        int leftTrue = countParenthesisUtil(str,i,k-1,true);
        int leftFalse = countParenthesisUtil(str,i,k-1,false);
        int rightTrue = countParenthesisUtil(str,k+1,j,true);
        int rightFalse = countParenthesisUtil(str,k+1,j,false);

        if(str[k]=='|')
        {
            if(isTrue)
                ans+=(leftTrue*rightTrue+leftTrue*rightFalse+leftFalse*rightTrue);
            else
                ans+=leftFalse*rightFalse;
        }
        else if(str[k]=='&')
        {
            if(isTrue)
                ans+=leftTrue*rightTrue;
            else
                ans+=leftFalse*rightFalse+leftTrue*rightFalse+leftFalse*rightTrue;
        }
        else if(str[k]=='^')
        {
            if(isTrue)
                ans+=leftTrue*rightFalse+rightTrue*leftFalse;
            else
                ans+=leftTrue*rightTrue+leftFalse*rightFalse;
        }
    }
    return dp[i][j][isTrue]=ans;
}


int countParenthesisDP(char *str,int len)
{
    int T[len][len],F[len][len];

    for(int i=0;i<len;i+=2)
    {
        if(str[i]=='T')
            T[i][i] = 1;
        else
            T[i][i] = 0;
        if(str[i]=='F')
            F[i][i] = 1;
        else
            F[i][i] = 0;
    }

    for(int gap=2;gap<len;gap+=2)
    {
        for(int i=0;(i+gap)<len;i+=2)
        {
            int j=i+gap,true_ans=0,false_ans=0;
            for(int k=i+1;k<j;k+=2)
            {
                if(str[k]=='|')
                {
                    true_ans+=T[i][k-1]*F[k+1][j]+T[i][k-1]*T[k+1][j]+F[i][k-1]*T[k+1][j];
                    false_ans+=F[i][k-1]*F[k+1][j];
                }
                if(str[k]=='&')
                {
                    true_ans+=T[i][k-1]*T[k+1][j];
                    false_ans+=T[i][k-1]*F[k+1][j]+F[i][k-1]*T[k+1][j]+F[i][k-1]*F[k+1][j];
                }
                if(str[k]=='^')
                {
                    true_ans+=T[i][k-1]*F[k+1][j]+F[i][k-1]*T[k+1][j];
                    false_ans+=T[i][k-1]*T[k+1][j]+F[i][k-1]*F[k+1][j];
                }
            }

            T[i][j] = true_ans;
            F[i][j] = false_ans;
        }
    }

    return T[0][len-1];
}

int countParenthesis(char str[],int len)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            for(int k=0;k<2;k++)
                dp[i][j][k] = -1;
    return countParenthesisDP(str,len);
}

int main()
{
	char symbols[] = "TTFT";
	char operators[] = "|&^";
	int n = strlen(symbols);

	char str[n+n];
	int i,j;

	for(i=0,j=0;symbols[i]!='\0';i++,j+=2)
        str[j]=symbols[i];

    for(j=0,i=1;operators[j]!='\0';j++,i+=2)
        str[i] = operators[j];

    str[i]='\0';

    cout<<countParenthesis(str,i);
	return 0;
}
