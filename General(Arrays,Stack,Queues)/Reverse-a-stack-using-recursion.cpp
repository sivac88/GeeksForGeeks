// C++ code to reverse a
// stack using recursion
#include<bits/stdc++.h>
using namespace std;

// using std::stack for
// stack implementation
stack<char> st;

// intializing a string to store
// result of reversed stack
string ns;


void insert_at_bottom(char x)
{
    if(st.size()>0)
    {
        char y = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(y);
    }
    else
    {
        st.push(x);
    }
}


char reverse()
{
	if(st.size()>0)
	{
        char x = st.top();
        st.pop();
		reverse();
		insert_at_bottom(x);
	}
}

// Driver Code
int main()
{

	// push elements into
	// the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');

	cout<<"Original Stack"<<endl;

	// print the elements
	// of original stack
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl;

	// function to reverse
	// the stack
	reverse();
	cout<<"Reversed Stack"
		<<endl;

	// storing values of reversed
	// stack into a string for display
	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		ns+=p;
	}

	//display of reversed stack
	cout<<ns[3]<<" "<<ns[2]<<" "
		<<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}

// This code is contributed by Gautam Singh
