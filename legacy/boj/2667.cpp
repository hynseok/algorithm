#include <bits/stdc++.h>
using namespace std;

int Map[26][26];
int visited[26][26];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void BFS(int y, int x, int house)
{
    visited[y][x]=1;
    for(int i=0;i<4;i++)
    {
        int moveY = y + dy[i];
        int moveX = x + dx[i];
        if(Map[moveY][moveX]==1&&visited[moveY][moveX]==0)
        {
            BFS(moveY,moveX,house+1);
        }
    }
}

int main()
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%1d",&Map[i][j]);
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(Map[i][j]==1&&visited[i][j]==0)
            {
                
                BFS(i,j,1);
            }
        }
    }
    
}