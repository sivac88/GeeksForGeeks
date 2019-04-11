// A O(n) program to find the largest subarray
// with equal number of 0s and 1s

#include <bits/stdc++.h>
using namespace std;

void findSubArray(int* a,int n)
{
    int sum[n],ans=0,max_i,max_j;
    unordered_map<int,int> m;
    sum[0]=((a[0]==0)?-1:1);
    for(int i=1;i<n;i++)
    {
        int val = ((a[i]==0)?-1:1);
        sum[i]=sum[i-1]+val;
        if(sum[i]==0)
        {
            ans=i+1;
            max_i=0;
            max_j=i;
        }
        else if(m.find(sum[i])==m.end())
            m[sum[i]]=i;
        else
        {
            if(ans<(i-sum[i]))
            {
                ans=i-sum[i];
                max_i=sum[i]+1;
                max_j=i;
            }
        }
    }

    if(ans!=0)
    cout<<"Max subarray length is:"<<ans<<" between the indices "<<max_i<<" and "<<max_j;
    else
    cout<<"No subarray with equal 1s and 0s";

}

/* Driver program to test above functions */
int main()
{
	int arr[] = {1, 0, 1, 1, 0, 0, 1};
	int size = sizeof(arr)/sizeof(arr[0]);

	findSubArray(arr, size);
	return 0;
}
