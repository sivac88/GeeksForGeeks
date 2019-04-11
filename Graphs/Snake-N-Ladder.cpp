// C++ program to find minimum number of dice throws required to
// reach last cell from first cell of a given snake and ladder
// board
#include<iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int getMinDiceThrows(int* moves,int n)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));
    queue<pair<int,int> > q;
    q.push({0,0});

    pair<int,int> p;

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        if(p.first == (n-1))
            break;

        for(int i=p.first+1;i<=(p.first+6) && i<n;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                if(moves[i]==-1)
                 q.push({i,p.second+1});
                else
                q.push({moves[i],p.second+1});
            }
        }
    }

    return p.second;
}

int main()
{
	// Let us construct the board given in above diagram
	int N = 30;
	int moves[N];
	for (int i = 0; i<N; i++)
		moves[i] = -1;

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
	return 0;
}
