// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;

/* A utility function to check whether a word
is present in dictionary or not. An array of
strings is used for dictionary. Using array
of strings for dictionary is definitely not
a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango", "icecream","and",
							"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

void wordBreakUtil(string s,string res)
{
    int len = s.length();
    if(len==0)
    {
        cout<<res<<endl;
        return;
    }
    for(int i=1;i<=len;i++)
    {
        string prefix = s.substr(0,i);
        if(dictionaryContains(prefix))
            wordBreakUtil(s.substr(i,len-i+1),res+prefix+" ");
    }
}

void wordBreak(string s)
{
    wordBreakUtil(s,"");
}

int main()
{
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}
