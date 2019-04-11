#include <bits/stdc++.h>
using namespace std;

stack<int> copy_contents(stack<int> s)
{
    stack<int> c;
    int count = 0,n=s.size();
    while(count != (n-1))
    {
        int top_element = s.top();
        s.pop();
        int dummy=1;
        while(dummy!=(n-count))
        {
            dummy++;
            c.push(s.top());
            s.pop();
        }
        s.push(top_element);
        while(!c.empty())
        {
            s.push(c.top());
            c.pop();
        }
        count++;
    }
    while(!s.empty())
    {
        c.push(s.top());
        s.pop();
    }
    return c;
}

void display(stack<int> s)
{
    while(!s.empty())
    {
        cout<<(s.top())<<" ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Original stack:"<<endl;
    display(s);
    cout<<endl;

    stack<int> copystack = copy_contents(s);

    cout<<"Copied stack:"<<endl;
    display(copystack);
    cout<<endl;

}
