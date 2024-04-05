#include <bits/stdc++.h>
using namespace std;

int N, M;
int Map[501][501];
int Tx[4][3] = {{1,0,0},{1,0,-1},{-1,0,0},{1,-1,0}};
int Ty[4][3] = {{0,1,-1},{0,1,0},{0,1,-1},{0,0,-1}};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct pos
{
    int x;
    int y;
    int length;
    int sum = 0;
};

int BFS(int x,int y, int num)
{
    int visited[501][501] = {0,};
    int ret = 0;
    queue<pos> Q;
    pos start;
    start.x = x; start.y = y; start.length = 1; start.sum += num;
    Q.push(start);
    visited[start.y][start.x] = 1;

    while(!Q.empty())
    {
        pos temp;
        temp = Q.front();
        Q.pop();

        if(temp.length==4)
        {
            ret = temp.sum;
            break;
        }
        pos next;    
        int Max=0;
        for(int i=0;i<4;i++)
        {
            int tx, ty;
            tx = temp.x + dx[i]; ty = temp.y + dy[i];
            if(tx>=0&&tx<M&&ty>=0&&ty<N)
            {
                if(visited[ty][tx]==0)
                {
                    if(Max<Map[ty][tx])
                    {
                        Max = Map[ty][tx];
                        next.x=tx; next.y=ty;
                        next.length = temp.length + 1;
                    }
                }
            }
        }
        if(next.length<=4)
        {
            next.sum = temp.sum + Map[next.y][next.x];
            Q.push(next);
            visited[next.y][next.x]=1;
        }
        
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>Map[i][j];
        }
    }
    
    int ans1 = 0;
    int ans2 = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int temp = BFS(j,i,Map[i][j]);
            if(ans1<temp) ans1 = temp;

            for(int k=0;k<4;k++)
            {
                int sum = 0;
                sum += Map[i][j];
                for(int l=0;l<3;l++)
                {
                    int tx = j + Tx[k][l];
                    int ty = i + Ty[k][l];
                    if(tx>=0&&tx<M&&ty>=0&&ty<N)
                    {
                        sum += Map[ty][tx];
                    }
                    else break;
                }
                if(ans2<sum) ans2 = sum;
            }
            
        }
    }
    
    int ans = max(ans1,ans2);
    cout<<ans;
}