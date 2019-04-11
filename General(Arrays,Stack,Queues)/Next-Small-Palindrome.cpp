#include <bits/stdc++.h>
using namespace std;

void generateNextPalindromeUtil(int* a,int n)
{
    int mid=n/2,i=mid-1,j=(n%2)?mid+1:mid,si=i,sj=j,sum;
    bool furtherProcess = false;
    while(i>=0)
    {
        if(a[j]==a[i])
            j++,i--;
        else
            break;
    }
    if(i<0 || a[j]>a[i])
        furtherProcess = true;
    while(i>=0){
        a[j++]=a[i--];
    }

    if(furtherProcess)
    {
        int carry = 1;
        if(n%2)
        {
            sum = a[mid]+carry;
            a[mid] = sum%10;
            carry = sum/10;
        }

        while(si>=0)
        {
            sum=a[si]+carry;
            a[si]=sum%10;
            a[sj]=a[si];
            carry=sum/10;
            si--,sj++;
        }
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

bool all9s(int* a,int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
        if(a[i]==9)
            count++;
    if(count==n)
        return true;
    return false;
}

void generateNextPalindrome(int* a,int n)
{
    if(all9s(a,n))
    {
        cout<<"1";
        for(int i=0;i<n;i++)
            cout<<"0";
        cout<<"1";
        return;
    }

    generateNextPalindromeUtil(a,n);
}


/* Utility that prints out an array on a line */
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Program to test above function
int main()
{
    int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};

    int n = sizeof (num)/ sizeof(num[0]);

    generateNextPalindrome( num, n );

    return 0;
}
