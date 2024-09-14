#include <bits/stdc++.h>
using namespace std;

int N, M;
int Map[1004][1004]={0,};
int visited[1004][1004]={0,};
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int ans = 0;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        if(ny==-1)ny = N-1; if(ny==N)ny = 0;
        int nx = x + dx[i];
        if(nx==-1)nx = M-1; if(nx==M)nx = 0;

        if(visited[ny][nx]||Map[ny][nx]==1) continue;
        dfs(ny,nx);
    }

    return;
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

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Map[i][j]==1) continue;
            if(visited[i][j]==1) continue;

            dfs(i,j);
            ans++;
        }
    }

    cout<<ans<<'\n';

    return 0;
}