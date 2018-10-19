//https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
#include <iostream>
using namespace std;

int n;
int mat[21][21];
bool visited[21][21];


bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
      return true;
      
    return false;
}

bool pathExists(int x,int y)
{
    if(mat[x][y]==2)
    return true;
    
    visited[x][y] = true;
    
    if(isValid(x+1,y) && !visited[x+1][y] && mat[x+1][y]!=0)
        if(pathExists(x+1,y))
         return true;
    if(isValid(x-1,y) && !visited[x-1][y] && mat[x-1][y]!=0)
        if(pathExists(x-1,y))
         return true;
    if(isValid(x,y+1) && !visited[x][y+1] && mat[x][y+1]!=0)
        if(pathExists(x,y+1))
         return true;
    if(isValid(x,y-1) && !visited[x][y-1] && mat[x][y-1]!=0)
        if(pathExists(x,y-1))
         return true;
         
    return false;
}

int main() {
	int t,s_x,s_y;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++){
	        cin>>mat[i][j];
	        visited[i][j]=false;
	        if(mat[i][j]==1)
	         s_x=i,s_y=j;
	      }
	        
	    if(pathExists(s_x,s_y))
	      cout<<1<<endl;
	    else
	      cout<<0<<endl;
	}
	return 0;
}