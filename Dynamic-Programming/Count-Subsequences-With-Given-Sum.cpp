#include<bits/stdc++.h>
using namespace std;

int countSubs(int* a,int n,int sum,map<pair<int,int>,int>& m)
{
  if(n==0 && sum==0) return 1;
  if(n==0) return 0;
  
  if(m.find({n,sum})!=m.end())
    return m[{n,sum}];

  m[{n,sum}]=countSubs(a,n-1,sum-a[n-1],m)+countSubs(a,n-1,sum,m);
  return m[{n,sum}];
}


int main()
{
	int t,n,q,sum;
  	cin>>t;
  	while(t--)
    {
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      cin>>q;
      while(q--)
      {
        cin>>sum;
        map<pair<int,int>,int> m;
        cout<<countSubs(a,n,sum,m)<< " ";
      }
      cout<<endl;

    }
}
