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

double getMedian(int* a,int al,int ah,int* b,int bl,int bh)
{
    if(al==ah)
        return (a[al]+b[bl])/2.0;

    if(ah==al+1)
        return (max(a[al],b[bl])+min(a[ah],b[bh]))/2.0;

    double a_median = findMedian(a,al,ah);
    double b_median = findMedian(b,bl,bh);

    int len = ah-al+1,a_mid =(al+ah)/2,b_mid=(bl+bh)/2;

    if(a_median == b_median)
        return a_median;

    if(a_median > b_median){
        if(len%2){
            return getMedian(a,al,a_mid,b,b_mid,bh);
        }
        else{
            return getMedian(a,al,a_mid+1,b,b_mid,bh);
        }
    }

    if(len%2)
        return getMedian(a,a_mid,ah,b,bl,b_mid);

    return getMedian(a,a_mid,ah,b,bl,b_mid+1);
}



// Driver code
int main()
{
	int ar1[] = {1, 2, 3, 6};
	int ar2[] = {4, 6, 8, 10};
	int n1 = sizeof(ar1) /
			sizeof(ar1[0]);
	int n2 = sizeof(ar2) /
			sizeof(ar2[0]);
	if (n1 == n2)
		cout << "Median is "
			<< getMedian(ar1,0,n1-1,ar2,0,n2-1);
	else
		cout << "Doesn't work for arrays "
			<< "of unequal size";
	return 0;
}

// This code is contributed
// by Shivi_Aggarwal
