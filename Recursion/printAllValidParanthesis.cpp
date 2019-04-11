// C program to Print all combinations
// of balanced parentheses
# include<stdio.h>
#include <bits/stdc++.h>
# define MAX_SIZE 100
using namespace std;

void printParenthesis(char* str,int n,int open,int close,int i)
{
    if(i==(2*n))
    {
        str[i]='\0';
        cout<<str<<endl;
        return;
    }

    if(open<n)
    {
        str[i] = '{';
        printParenthesis(str,n,open+1,close,i+1);
    }

    if(close<open)
    {
        str[i] = '}';
        printParenthesis(str,n,open,close+1,i+1);
    }
}

int main()
{
	int n = 3;
	char str[(2*n)+1];
	printParenthesis(str,n,0,0,0);
	return 0;
}
