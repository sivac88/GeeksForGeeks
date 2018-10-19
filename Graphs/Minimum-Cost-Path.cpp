//https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
    int dist;
    point(int x,int y,int dist) : x(x),y(y),dist(dist) {}
};

typedef struct point point;

#define MAX_N 51

int n;
int mat[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

bool operator<(const point& p1,const point& p2)
{
    if(p1.dist == p2.dist)
    {
         if(p1.x != p2.x)
            return p1.x < p2.x;
         return p1.y-p2.y;
    }
    return p1.dist < p2.dist;
}

bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
        return true;
    return false;
}

int minDistance()
{
    set<point> s;
    dist[0][0] = mat[0][0];
    s.insert(point(0,0,dist[0][0]));
    while(!s.empty())
    {
          point minPoint = *s.begin();
          s.erase(s.begin());

          if(isValid((minPoint.x)+1,minPoint.y) &&
             dist[(minPoint.x)+1][minPoint.y] >
             dist[minPoint.x][minPoint.y]+ mat[(minPoint.x)+1][minPoint.y])
          {
              if(dist[(minPoint.x)+1][minPoint.y] != INT_MAX)
                s.erase(s.find(point((minPoint.x)+1,minPoint.y,dist[(minPoint.x)+1][minPoint.y])));

              dist[(minPoint.x)+1][minPoint.y] = dist[minPoint.x][minPoint.y]+ mat[(minPoint.x)+1][minPoint.y];
              s.insert(point((minPoint.x)+1,minPoint.y,dist[(minPoint.x)+1][minPoint.y]));
          }

          if(isValid((minPoint.x)-1,minPoint.y) &&
             dist[(minPoint.x)-1][minPoint.y] >
             dist[minPoint.x][minPoint.y]+ mat[(minPoint.x)-1][minPoint.y])
          {
              if(dist[(minPoint.x)-1][minPoint.y] != INT_MAX)
                s.erase(s.find(point((minPoint.x)-1,minPoint.y,dist[(minPoint.x)-1][minPoint.y])));

              dist[(minPoint.x)-1][minPoint.y] = dist[minPoint.x][minPoint.y]+ mat[(minPoint.x)-1][minPoint.y];
              s.insert(point((minPoint.x)-1,minPoint.y,dist[(minPoint.x)-1][minPoint.y]));
          }

          if(isValid(minPoint.x,(minPoint.y)+1) &&
             dist[minPoint.x][(minPoint.y)+1] >
             dist[minPoint.x][minPoint.y]+ mat[minPoint.x][(minPoint.y)+1])
          {
              if(dist[minPoint.x][(minPoint.y)+1] != INT_MAX)
                s.erase(s.find(point(minPoint.x,(minPoint.y)+1,dist[minPoint.x][(minPoint.y)+1])));

              dist[minPoint.x][(minPoint.y)+1] = dist[minPoint.x][minPoint.y]+ mat[minPoint.x][(minPoint.y)+1];
              s.insert(point(minPoint.x,(minPoint.y)+1,dist[minPoint.x][(minPoint.y)+1]));
          }

            if(isValid(minPoint.x,(minPoint.y)-1) &&
             dist[minPoint.x][(minPoint.y)-1] >
             dist[minPoint.x][minPoint.y]+ mat[minPoint.x][(minPoint.y)-1])
          {
              if(dist[minPoint.x][(minPoint.y)-1] != INT_MAX)
                s.erase(s.find(point(minPoint.x,(minPoint.y)-1,dist[minPoint.x][(minPoint.y)-1])));

              dist[minPoint.x][(minPoint.y)-1] = dist[minPoint.x][minPoint.y]+ mat[minPoint.x][(minPoint.y)-1];
              s.insert(point(minPoint.x,(minPoint.y)-1,dist[minPoint.x][(minPoint.y)-1]));
          }
    }

    return dist[n-1][n-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                dist[i][j]=INT_MAX;
            }
        cout<<minDistance()<<endl;
    }
    return 0;
}
