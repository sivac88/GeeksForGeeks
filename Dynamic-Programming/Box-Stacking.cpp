//Problem Description : https://practice.geeksforgeeks.org/problems/box-stacking/1
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct block
{
  int height;
  int width;
  int length;
};

typedef struct block blocks;

int cmp(const void* a,const void* b)
{
    return ((((block*)a)->length) * (((block*)a)->width)) -
           ((((block*)b)->length) * (((block*)b)->width));

}


bool checkIfPossible(block a,block b)
{
    if((a.length > b.length) && (a.width > b.width))
    return true;

    return false;
}

int maxHeight(block old_blocks[],int n)
{
    block blocks[3*n];
    for(int i=0;i<n;i++)
    {
        blocks[3*i].height = old_blocks[i].height;
        blocks[3*i].length = max(old_blocks[i].width,old_blocks[i].length);
        blocks[3*i].width  = min(old_blocks[i].width,old_blocks[i].length);

        blocks[(3*i)+1].height = old_blocks[i].length;
        blocks[(3*i)+1].length = max(old_blocks[i].width,old_blocks[i].height);
        blocks[(3*i)+1].width  = min(old_blocks[i].width,old_blocks[i].height);

        blocks[(3*i)+2].height = old_blocks[i].width;
        blocks[(3*i)+2].length = max(old_blocks[i].length,old_blocks[i].height);
        blocks[(3*i)+2].width  = min(old_blocks[i].length,old_blocks[i].height);
    }

    qsort(blocks,3*n,sizeof(blocks[0]),cmp);

    int ans[3*n],res=1;

    for(int i=0;i<3*n;i++)
    ans[i] = blocks[i].height;

    for(int i=1;i<3*n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(checkIfPossible(blocks[i],blocks[j]) && ans[i] < ans[j]+blocks[i].height)
            {
                ans[i] = ans[j]+blocks[i].height;
                res=max(res,ans[i]);
            }
        }
    }

    return res;
}

int main()
{
   int t,n;
   cin>>t;
   while(t--)
   {
       cin>>n;
       block blocks[n];
       for(int i=0;i<n;i++)
       {
           cin>>blocks[i].height;
           cin>>blocks[i].width;
           cin>>blocks[i].length;
       }
       cout<<maxHeight(blocks,n)<<endl;
   }
}
