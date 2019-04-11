// CPP program to count the Number
// of subarrays with m odd numbers
// O(N) approach
#include <bits/stdc++.h>
using namespace std;

// fucntion that returns the count
// of subarrays with m odd numbers
int countSubarrays(int a[], int n, int m)
{
	int count = 0;
	int prefix[n] = { 0 };
	int odd = 0;

	// traverse in the array
	for (int i = 0; i < n; i++)
	{

		prefix[odd]++;

		// if array element is odd
		if (a[i] & 1)
			odd++;

		// when number of odd elements>=M
		if (odd >= m)
			count += prefix[odd - m];
	}

	return count;
}

// Driver Code
int main()
{
	int a[] = { 2, 2, 5, 6, 9, 2, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	int m = 2;

	cout << countSubarrays(a, n, m);

	return 0;
}
