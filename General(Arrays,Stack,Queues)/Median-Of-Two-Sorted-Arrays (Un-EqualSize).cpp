// A divide and conquer based
// efficient solution to find
// median of two sorted arrays
// of same size.
#include<bits/stdc++.h>
using namespace std;

double findMedian(int* a,int l,int h)
{
    int n = (h-l)+1;

    if(n%2)
    return a[(l+h)/2];

    return ((double)(a[(l+h)/2]+a[((l+h)/2)+1]))/2.0;

}

double getMedian(int* a,int n1,int* b,int n2)
{
    int l=0,h=n1,total=n1+n2;
    while(l<=h)
    {
        int partitionX = (l+h)/2;
        int partitionY = (total+1)/2 - partitionX;

        int maxLeftX = (partitionX==0) ? INT_MIN : a[partitionX-1];
        int maxLeftY = (partitionY==0) ? INT_MIN : b[partitionY-1];

        int minRightX = (partitionX==n1) ? INT_MAX : a[partitionX];
        int minRightY = (partitionY==n2) ? INT_MAX : b[partitionY];

        if((maxLeftX <= minRightY) && (maxLeftY<=minRightX))
        {
            if(total%2)
                return max(maxLeftX,maxLeftY);
            else
                return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
        }

        if(maxLeftX > minRightY)
            h=partitionX-1;
        else
            l=partitionX+1;
    }
    return -1;
}


// Driver code
int main()
{
    int ar1[] = {1,3,5,7};
    int ar2[] = {2,4;
    int n1 = sizeof(ar1) /
            sizeof(ar1[0]);
    int n2 = sizeof(ar2) /
            sizeof(ar2[0]);

    double ans;

    if(n1>n2)
        ans = getMedian(ar1,n1,ar2,n2);
    else
        ans = getMedian(ar2,n2,ar1,n1);

    cout<<ans;
    return 0;
}

// This code is contributed
// by Shivi_Aggarwal
