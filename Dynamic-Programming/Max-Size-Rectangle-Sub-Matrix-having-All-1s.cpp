// C++ program to find largest rectangle with all 1s
// in a binary matrix
#include<bits/stdc++.h>
using namespace std;

// Rows and columns in input matrix
#define R 4
#define C 4

int largestHistogramArea(int* arr)
{
    stack<int> s;
    int n = C;
    int ans = -1,cur,prev;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            cur = s.top();
            s.pop();
            if(s.empty())
                prev = -1;
            else
                prev = s.top();
            ans = max(ans,(i-prev-1)*arr[cur]);
        }
        s.push(i);
    }

    while(!s.empty())
    {
        cur=s.top();
        s.pop();
        if(s.empty())
            prev = -1;
        else
            prev = s.top();
        ans = max(ans,(n-prev-1)*arr[cur]);
    }

    return ans;
}

int maxRectangle(int A[R][C])
{
    int hist[C];
    memset(hist,0,sizeof(hist));
    int max_area = 0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++){
            if(A[i][j])
                hist[j]+=A[i][j];
            else
                hist[j] = 0;
        }

        max_area = max(max_area,largestHistogramArea(hist));
    }

    return max_area;
}


// Driver code
int main()
{
	int A[][C] = { {0, 1, 1, 0},
				{1, 1, 1, 1},
				{1, 1, 1, 1},
				{1, 1, 0, 0},
				};

	cout << "Area of maximum rectangle is " << maxRectangle(A);

	return 0;
}
