// C++ program to check whether reversing a sub array
// make the array sorted or not
#include<bits/stdc++.h>
using namespace std;

// Return true, if reversing the subarray will sort t
// he array, else return false.
bool checkReverse(int arr[], int n)
{
	if (n == 1)
		return true;

	// Find first increasing part
	int i;
	for (i=1; i < n && arr[i-1] < arr[i]; i++);
	if (i == n)
		return true;

	// Find reversed part
	int j = i;
	while (arr[j] < arr[j-1])
	{
		if (i > 1 && arr[j] < arr[i-2])
			return false;
		j++;
	}

	if (j == n)
		return true;

	// Find last increasing part
	int k = j;

	// To handle cases like {1,2,3,4,20,9,16,17}
	if (arr[k] < arr[i-1])
	return false;

	while (k > 1 && k < n)
	{
		if (arr[k] < arr[k-1])
			return false;
		k++;
	}
	return true;
}

// Driven Program
int main()
{
	int arr[] = {1,2,3,4,20,9,16,17};
	int n = sizeof(arr)/sizeof(arr[0]);
	checkReverse(arr, n)? cout << "Yes" : cout << "No";
	return 0;
}
