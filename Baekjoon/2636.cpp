#include <bits/stdc++.h>
using namespace std;


int M, N, ans1=0, ans2=0;
int Map[101][101] = {0, };
int visited[101][101] = {0, };
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<pair<int,int> > V;

void go(int y, int x)
{  
    visited[y][x] = 1;

    if(Map[y][x]==1)
    {
        V.push_back(make_pair(y,x));
        return;
    }

    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx])continue;

        go(ny,nx);
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

    while(true)
    {
        fill(&visited[0][0],&visited[0][0]+101*101,0);
        V.clear();
        ans2 = 0;
        go(0,0);
        for(pair<int,int> idx : V)
        {
            Map[idx.first][idx.second] = 0;
            ans2++;
        }
        int tok = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(Map[i][j]==1)tok=1;
            }
        }
        ans1++;

        if(tok==0)break;
    }
    cout<<ans1<<'\n'<<ans2<<'\n';
    return 0;
}