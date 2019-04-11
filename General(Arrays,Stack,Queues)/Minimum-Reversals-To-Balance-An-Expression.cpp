// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;

int countMinReversals(string str)
{
    int n = str.length();
    if(n%2) return -1;
    float open=0,close=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='{')
            open++;
        else if(str[i]=='}')
        {
            if(open==0)
                close++;
            else
                open--;
        }
    }

    return ceil(open/2.0)+ceil(close/2.0);
}

// Driver Code
int main()
{
	string expr = "}{{}}{{{";

	cout << countMinReversals(expr);

	return 0;
}
