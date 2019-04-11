#include <bits/stdc++.h>
using namespace std;

char *mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void letterCombinationsUtil(int* num,int n,int cur,char* res)
{
    if(cur==n)
    {
        res[cur]='\0';
        cout<<res<<endl;
        return;
    }

    for(int i=0;mapping[num[cur]][i]!='\0';i++)
    {
        res[cur] = mapping[num[cur]][i];
        letterCombinationsUtil(num,n,cur+1,res);
    }
}

void letterCombinations(int* num,int n)
{
    char res[n+1];
    letterCombinationsUtil(num,n,0,res);
}

int main()
{
	int number[] = {5,6,7};
	int n = sizeof(number) / sizeof(number[0]);

	letterCombinations(number, n);

	return 0;
}
