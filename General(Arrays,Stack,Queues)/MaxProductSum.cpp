// C++ program to find maximum subarray product.
#include <bits/stdc++.h>

using namespace std;

int findMaxProduct(int* a,int n)
{
    int minVal=1,maxVal=1,ans=0,prevMax;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            maxVal = a[i]*maxVal;
            minVal = min(1,a[i]*minVal);
        }
        else if(a[i]==0)
        {
            maxVal = 0;
            minVal = 1;
        }
        else
        {
            prevMax = maxVal;
            maxVal = minVal*a[i];
            minVal = a[i]*prevMax;
        }
        ans = max(ans,maxVal);
        if(maxVal<=0)
            maxVal = 1;
    }
    return ans;
}

int main()
{
    int arr[] = {-2, -3, 0, -2, -40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxProduct(arr, n);
    return 0;
}
