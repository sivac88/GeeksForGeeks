// C++ program to find top k elements in a stream
#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator() (const pair<int,int> &a, const pair<int,int> &b) const
  {
      if(a.first==b.first)
      {
            return a.second<(b.second);
      }
      return a.first>(b.first);
  }
};

void kTop(int* a,int n,int k)
{
    set<pair<int,int>,cmp> s;
    map<int,int> m;

    for(int i=0;i<n;i++)
    {
        if(m[a[i]]==0)
        {
            m[a[i]]++;
            s.insert({m[a[i]],a[i]});
        }
        else
        {
            s.erase({m[a[i]],a[i]});
            m[a[i]]++;
            s.insert({m[a[i]],a[i]});
        }

        int count = 0;
        for(pair<int,int> p:s)
        {
            if(count==k)break;
            cout<<p.second<<" ";
            count++;
        }
    }
}

// Driver program to test above function
int main()
{
    int k = 4;
    int arr[] = { 5, 2, 1, 3, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    kTop(arr, n, k);
    return 0;
}
