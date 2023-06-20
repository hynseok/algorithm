#include <bits/stdc++.h>
using namespace std;

int N;
char Map[101][101];
int visited[101][101]={0,};
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void BFS(int y, int x)
{
    visited[y][x]=1;
    int nextX,nextY;
    for(int i=0;i<4;i++)
    {
        nextX = x + dx[i];
        nextY = y + dy[i];
        if(nextX>=0&&nextX<N&&nextY>=0&&nextY<N)
        {
            if(Map[y][x]==Map[nextY][nextX]&&visited[nextY][nextX]==0)
            {
                BFS(nextY,nextX);
            }
        }
    }
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf(" %1c",&Map[i][j]);
        }
    }
    
    int norm = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]==0)
            {
                BFS(i,j);
                norm++;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Map[i][j]=='G') Map[i][j] = 'R';
        }
    }
    for(int i=0;i<N;i++)
    {
        memset(visited[i],0,N*sizeof(int));
    }

    int CW = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]==0)
            {
                BFS(i,j);
                CW++;
            }
        }
    }

    cout<<norm<<' '<<CW;

    return 0;

}