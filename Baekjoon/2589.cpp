#include <bits/stdc++.h>
using namespace std;

int Map[54][54]; // 육지 1 바다 2
int visited[54][54];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int N, M;


int bfs(int y, int x)
{
    int ret = -1;
    queue<pair<pair<int,int>,int> > Q;
    visited[y][x] = 1;
    Q.push(make_pair(make_pair(y,x),0));

    while(!Q.empty())
    {
        int nowy = Q.front().first.first;
        int nowx = Q.front().first.second;
        int dist = Q.front().second;
        if(ret<dist)ret=dist;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nexty = nowy+dy[i];
            int nextx = nowx+dx[i];

            if(nexty<0||nexty>=N||nextx<0||nextx>=M||visited[nexty][nextx]||Map[nexty][nextx]==2) continue;
            visited[nexty][nextx] = 1;
            Q.push(make_pair(make_pair(nexty,nextx),dist+1));

        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ans = -1;

    cin>>N>>M;

    char temp;
    string tstr;
    for(int i=0;i<N;i++)
    {
        cin>>tstr;
        for(int j=0;j<M;j++)
        {
            temp=tstr[j];
            if(temp=='W')Map[i][j] = 2;
            else if(temp=='L')Map[i][j] = 1;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Map[i][j]==2)continue;
            fill(&visited[0][0],&visited[53][54],0);
            int tans = bfs(i,j);
            if(ans<tans)ans=tans;
        }
    }
    
    
    cout<<ans<<'\n';

    return 0;
}