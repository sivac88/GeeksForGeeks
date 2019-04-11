// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool cmp(Job &a,Job &b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job* arr,int n)
{
    sort(arr,arr+n,cmp);
    pair<bool,char> available[n+1];
    for(int i=0;i<n;i++)
        available[i].first = true;
    int profit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline);j>=0;j--)
        {
            if(available[j].first)
            {
                available[j].first = false;
                available[j].second = arr[i].id;
                profit+=arr[i].profit;
                break;
            }
        }
    }

    cout<<"Total profit that we can get is:"<<profit<<endl;
    cout<<"Following is maximum profit sequence of jobs \n";
    for(int i=1;i<n;i++)
    {
        if(!available[i].first)
            cout<<available[i].second<<" ";
    }
}

// Driver program to test methods
int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
				{'d', 1, 25}, {'e', 3, 15}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printJobScheduling(arr, n);
	return 0;
}
