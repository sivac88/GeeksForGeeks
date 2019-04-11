//https://www.geeksforgeeks.org/minimum-steps-to-reach-a-destination/
#include<bits/stdc++.h>
using namespace std;

int minSteps(int n,int step,int cur)
{
    if(abs(cur)>abs(n)) return INT_MAX;
    if(cur==n) return step-1;
    return min(minSteps(n,step+1,cur+step),minSteps(n,step+1,cur-step));
}

int main()
{
    int n=8;
    cout<<minSteps(n,1,0);
}
