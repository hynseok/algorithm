#include <bits/stdc++.h>
using namespace std;

int M, N, T;
int field[51][51];
int visited[51][51];

void dfs(int x, int y)
{
    visited[y][x]=1;
    if(x+1<M)
    {
        if(visited[y][x+1]==0&&field[y][x+1]==1)
            dfs(x+1,y);
    }
    if(x-1>=0)
    {
        if(visited[y][x-1]==0&&field[y][x-1]==1)
            dfs(x-1,y);
    }
    if(y+1<N)
    {
        if(visited[y+1][x]==0&&field[y+1][x]==1)
            dfs(x,y+1);
    }
    if(y-1>=0)
    {
        if(visited[y-1][x]==0&&field[y-1][x]==1)
            dfs(x,y-1);
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for(int i=0;i<T;i++)
    {
        int tx, ty, tc;
        int ans=0;
        cin >> M >> N >> tc;

        for(int j=0;j<tc;j++)
        {
            cin >> tx >> ty;
            field[ty][tx]=1;
        }

        for(int j=0;j<N;j++)
        {
            
            for(int k=0;k<M;k++)
            {
                if(field[j][k]==1&&visited[j][k]==0)
                {
                    dfs(k,j);
                    ans++;
                }
                
            }
        }

        cout<<ans<<'\n';
        
        memset(field,0,sizeof(field));
        memset(visited,0,sizeof(visited));



    }   
}