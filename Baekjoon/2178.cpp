#include <bits/stdc++.h>
using namespace std;

int Map[102][102] = {0, };
int visited[102][102] = {0, };
int M, N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Pos
{
    int y;
    int x;
    int length;
};

void BFS(int startX, int startY)
{
    queue<Pos> Q;
    visited[startY][startX] = 1;
    Q.push({startY,startX,1});

    while(!Q.empty())
    {
        Pos temp;
        temp = Q.front();
        Q.pop();
        if(temp.y==N&&temp.x==M)cout<<temp.length;
        for(int i=0;i<4;i++)
        {
            int moveX = temp.x + dx[i];
            int moveY = temp.y + dy[i];
            if(visited[moveY][moveX]==0&&Map[moveY][moveX]==1)
            {
                visited[moveY][moveX] = 1;
                Q.push({moveY,moveX,temp.length+1});
            }
        }

    }

}

int main()
{

    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int temp;
            scanf("%1d",&Map[i][j]);
        }
    }
    
    BFS(1,1);


}