// C++ program to find length of the shortest chain
// transformation from source to target
#include<bits/stdc++.h>
using namespace std;

bool isAdjacent(string& a,string& b)
{
    if(a.length() != b.length())
        return false;

    int mismatch = 0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
            mismatch++;
        if(mismatch > 1) return false;
    }
    if(mismatch==1) return true;
    return false;
}

int shortestChainLen(string &source,string &target,set<string>& s)
{
    queue<pair<string,int> > q;
    q.push({source,1});

    set<string> visited;

    while(!q.empty())
    {
        pair<string,int> p = q.front();
        q.pop();
        for(string str : s)
        {
            if(isAdjacent(p.first,str) && visited.find(str)==visited.end())
            {
                if(str == target)
                    return p.second+1;
                q.push({str,p.second+1});
                visited.insert(str);
            }
        }
    }
    return 0;
}

// Driver program
int main()
{
	// make dictionary
	set<string> D;
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");
	D.insert("plea");
	string start = "toon";
	string target = "plea";
	cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D);
	return 0;
}
