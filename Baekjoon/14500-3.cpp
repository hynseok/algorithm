

#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 0;
int Map[501][501];
int visited[501][501]={0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS(int x,int y, int cnt, int num)
{
    if(cnt==4)
    {
        if(ans<num) ans = num;
        return;
    }

    for(int i=0;i<4;i++)
    {
        int nextX, nextY;
        nextX = x + dx[i];
        nextY = y + dy[i];

        if(nextX<0||nextX>=N||nextY<0||nextY>=M||visited[nextX][nextY]!=0) continue;
        
        visited[nextX][nextY]=1;
        DFS(nextX,nextY,cnt+1,num+Map[nextX][nextY]);
        visited[nextX][nextY]=0;
        
    }
    
    
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
            visited[i][j]=1;
            DFS(i,j,1,Map[i][j]);
            visited[i][j]=0;
            if(j-1>=0&&i-1>=0&&i+1<N) ans = max(ans, Map[i][j]+Map[i][j-1]+Map[i-1][j]+Map[i+1][j]);
            if(j+1<M&&i-1>=0&&i+1<N) ans = max(ans, Map[i][j]+Map[i][j+1]+Map[i-1][j]+Map[i+1][j]);
            if(j+1<M&&i-1>=0&&j-1>=0) ans = max(ans, Map[i][j]+Map[i][j+1]+Map[i][j-1]+Map[i-1][j]);
            if(j+1<M&&j-1>=0&&i+1<N) ans = max(ans, Map[i][j]+Map[i][j+1]+Map[i][j-1]+Map[i+1][j]);
        }
    }
    
    cout<<ans;
}