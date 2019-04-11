// A Dynamic Programming based program to test whether a given string can
// be segmented into space separated words in dictionary
#include <iostream>
#include <string.h>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
An array of strings is used for dictionary. Using array of strings for
dictionary is definitely not a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
						"icecream","and","go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

bool wordBreak(string s)
{
    int len = s.length();
    if(len==0) return true;
    for(int i=1;i<=len;i++)
    {
        string prefix = s.substr(0,i);
        if(dictionaryContains(prefix) && wordBreak(s.substr(i,len-i+1)))
            return true;
    }
    return false;
}

bool wordBreakDP(string s)
{
    int len = s.length();
    if(len==0) return true;
    bool dp[len][len];
    memset(dp,false,sizeof(dp));
    for(int gap=1;gap<=len;gap++)
    {
        for(int i=0,j=gap-1;j<len;j++,i++)
        {
            if(gap==1)
            {
                if(dictionaryContains(s.substr(i,gap)))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                for(int k=1;k<=gap;k++)
                {
                    if(dictionaryContains(s.substr(i,k)) && (k==gap || dp[i+k][j])){
                        dp[i][j]=true;
                        if(dp[i][j])
                            break;
                    }
                }
            }
        }
    }
    return dp[0][len-1];
}

bool wordBreakDPOptimal(string s)
{
    int len = s.length();
    if(len==0) return true;
    bool dp[len+1];
    memset(dp,false,sizeof(dp));
    for(int i=1;i<=len;i++)
    {
        if(dp[i]==false && dictionaryContains(s.substr(0,i)))
            dp[i] = true;

        if(dp[i])
        {
            if(i==len)
                return true;
            for(int j=i+1;j<=len;j++)
            {
                if(dp[j]==false && dictionaryContains(s.substr(i,j-i)))
                    dp[j] = true;
                if(j==len && dp[j])
                    return true;
            }
        }
    }
    return false;
}

// Driver program to test above functions
int main()
{
    wordBreakDPOptimal("ilike")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreakDPOptimal("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}
