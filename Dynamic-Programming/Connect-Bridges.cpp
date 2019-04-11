// C++ implementation of building bridges
#include <bits/stdc++.h>

using namespace std;

// north-south coodinates
// of each City Pair
struct CityPairs
{
  int north, south;
};

bool cmp(CityPairs a,CityPairs b)
{
    if(a.south==b.south)
        return a.north < b.north;

    return a.south < b.south;
}

int maxBridges(CityPairs values[],int n)
{
    sort(values,values+n,cmp);
    int lis[n];
    for(int i=0;i<n;i++) lis[i] = 1;

    int ans = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(values[i].north >= values[j].north && (lis[i]<1+lis[j]))
                lis[i]=1+lis[j];
        }
        ans = max(ans,lis[i]);
    }
    return ans;
}

// Driver program to test above
int main()
{
  struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
  int n = 4;
  cout << "Maximum number of bridges = "
      << maxBridges(values, n);
  return 0;
}
