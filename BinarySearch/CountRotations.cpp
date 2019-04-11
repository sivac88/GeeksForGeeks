// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
#include<bits/stdc++.h>
using namespace std;

int countRotations(int* a,int l,int h)
{
    if(l>h) return 0;
    if(l==h) return l;
    int mid = (l+h)/2;
    if(mid<h && a[mid]>a[mid+1])
        return mid+1;
    if(mid>l && a[mid]<a[mid-1])
        return mid;
    if(a[h]>a[mid])
        return countRotations(a,l,mid-1);
    return countRotations(a,mid+1,h);
}

// Driver code
int main()
{
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << countRotations(arr, 0, n-1);
	return 0;
}
