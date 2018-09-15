//Problem Description : https://practice.geeksforgeeks.org/problems/champagne-overflow/0
#include <iostream>
#include <string.h>
using namespace std;

float getWaterinGlass(int k,int i,int j)
{
    float glass[i*(i+1)/2],current_glass_water,overflow;
    memset(glass,0.0f,sizeof(glass));
    int idx=0;
    glass[idx] = k;
    
    for(int row=1;row<i;row++)
    {
        for(int column=0;column<row;column++,idx++)
        {
            current_glass_water = glass[idx];
            overflow = 0;
            
            if(current_glass_water >= 1.0f)
            {
                glass[idx] = 1.0f;
                overflow = current_glass_water-1.0f;
            }
            
            glass[row+idx] += overflow/2;
            glass[row+idx+1] += overflow/2;
            
        }
    }
    
    float ans = glass[(i*(i-1)/2)+j-1];
    if(ans >= 1.0f)
    return 1.0f;
    
    return ans;
}

int main() {
	int t,k,i,j;
	cin>>t;
	while(t--)
	{
	   cin>>k>>i>>j;
	   cout<<getWaterinGlass(k,i,j)<<endl;
	}
	return 0;
}