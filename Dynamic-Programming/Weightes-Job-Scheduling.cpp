// C++ program for weighted job scheduling using Dynamic Programming.
#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
	int start, finish, profit;
};

bool cmp(Job &a,Job &b)
{
    return (a.finish < b.finish);
}

int getIdx(Job* arr,int idx)
{
    for(int i=idx-1;i>=0;i--)
    {
        if(arr[i].finish <= arr[idx].start)
            return i;
    }
    return -1;
}

int findMaxProfit(Job* arr,int n)
{
    sort(arr,arr+n,cmp);
    int profit[n];
    profit[0]=arr[0].profit;
    for(int i=1;i<n;i++)
    {
        int incl=arr[i].profit;
        int prev_idx = getIdx(arr,i);
        if(prev_idx!=-1)
            incl+=profit[prev_idx];
        int excl=profit[i-1];
        profit[i] = max(incl,excl);
    }
    return profit[n-1];
}

// Driver program
int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
