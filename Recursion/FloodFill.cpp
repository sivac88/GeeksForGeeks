// A C++ program to replace all 'O's with 'X''s if surrounded by 'X'
#include<iostream>
using namespace std;

// Size of given matrix is M X N
#define M 6
#define N 6

bool isValid(int x,int y)
{
    if(x>=0 && x<M && y>=0 && y<N)
        return true;
    return false;
}

void floodfill(char mat[M][N],int x,int y,char toChange,char to)
{
    mat[x][y]=to;
    if(isValid(x-1,y) && mat[x-1][y]==toChange)
        floodfill(mat,x-1,y,toChange,to);
    if(isValid(x+1,y) && mat[x+1][y]==toChange)
        floodfill(mat,x+1,y,toChange,to);
    if(isValid(x,y-1) && mat[x][y-1]==toChange)
        floodfill(mat,x,y-1,toChange,to);
    if(isValid(x,y+1) && mat[x][y+1]==toChange)
        floodfill(mat,x,y+1,toChange,to);
}


void replaceSurrounded(char mat[M][N])
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]=='O')
                mat[i][j] = '-';
        }
    }

    for(int i=0;i<N;i++)
        if(mat[0][i]=='-')
            floodfill(mat,0,i,'-','O');
    for(int i=0;i<N;i++)
        if(mat[M-1][N]=='-')
            floodfill(mat,M-1,i,'-','O');
    for(int i=0;i<M;i++)
        if(mat[i][0]=='-')
            floodfill(mat,i,0,'-','O');
    for(int i=0;i<M;i++)
        if(mat[i][N-1]=='-')
            floodfill(mat,i,N-1,'-','O');

    //replace remianing - with Xs
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]=='-')
                mat[i][j]='X';
        }
    }
}

// Driver program to test above function
int main()
{
	char mat[][N] = {{'X', 'O', 'X', 'O', 'X', 'X'},
					{'X', 'O', 'X', 'X', 'O', 'X'},
					{'X', 'X', 'X', 'O', 'X', 'X'},
					{'O', 'X', 'X', 'X', 'X', 'X'},
					{'X', 'X', 'X', 'O', 'X', 'O'},
					{'O', 'O', 'X', 'O', 'O', 'O'},
					};
	replaceSurrounded(mat);


	for (int i=0; i<M; i++)
	{
	for (int j=0; j<N; j++)
		cout << mat[i][j] << " ";
	cout << endl;
	}
	return 0;
}
