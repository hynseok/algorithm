#include <bits/stdc++.h>
using namespace std;

char Map[21][21];
int visited[26];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int T;
int R, C;
int ans;

void dfs(int y, int x, int cnt)
{
    if(ans<cnt) ans=cnt;
    
    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<1||ny>R||nx<1||nx>C||visited[Map[ny][nx]-'A']) continue;

        visited[Map[ny][nx]-'A']=1;   
        dfs(ny,nx,cnt+1);
        visited[Map[ny][nx]-'A']=0;

    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    int n=1;
    while(T--)
    {
        ans=0;
        cin>>R>>C;
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                cin>>Map[i][j];
            }
        }

        visited[Map[1][1]-'A']=1;
        dfs(1,1,1);
        visited[Map[1][1]-'A']=0;

        cout<<'#'<<n<<' '<<ans<<'\n';
        n++;
    }
}