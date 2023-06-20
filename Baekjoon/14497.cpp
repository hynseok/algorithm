#include <bits/stdc++.h>
using namespace std;

int N, M;
int Map[304][304];
int visited[304][304];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int tokken = 0;
int ans = 0;
pair<int,int> J, C; 

void DFS(int y, int x)
{
    if(Map[y][x]==2)
    {
        Map[y][x] = 0;
        tokken = 1;
        return;
    }
    if(Map[y][x]==1)
    {
        Map[y][x] = 0;
        return;
    }

    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(visited[ny][nx]||ny<1||ny>N||nx<1||nx>M) continue;
        visited[ny][nx] = 1;
        DFS(ny,nx);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    cin>>J.first>>J.second;
    cin>>C.first>>C.second;

    int temp;
    string tstring;
    for(int i=0;i<N;i++)
    {
        cin>>tstring;
        for(int j=0;j<M;j++)
        {
            if(i+1==C.first&&j+1==C.second) Map[i+1][j+1] = 2;
            else if(i+1==J.first&&j+1==J.second) Map[i+1][j+1] = 3;
            else
            {
                temp = tstring[j]-'0';
                Map[i+1][j+1] = temp;
            }
            
        }
    }   

    while(tokken!=1)
    {
        ans++;
        memset(visited,0,sizeof(visited));
        visited[J.first][J.second] = 1;
        DFS(J.first,J.second);
    }

    cout<<ans<<'\n';
    return 0;
}