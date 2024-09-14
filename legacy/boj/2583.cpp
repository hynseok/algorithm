#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int Map[100][100]={0, };
int visited[100][100]={0, };
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<int> AV;
int A, num=0;

void DFS(int nowy, int nowx)
{
    visited[nowy][nowx] = 1;
    A++;

    for(int i=0;i<4;i++)
    {
        int nexty = nowy + dy[i];
        int nextx = nowx + dx[i];

        if(nexty<0||nexty>=M||nextx<0||nextx>=N||visited[nexty][nextx]==1||Map[nexty][nextx]>0)continue;

        DFS(nexty,nextx);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    cin>>M>>N>>K;

    for(int i=0;i<K;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        for(int j=y1;j<y2;j++)
        {
            for(int k=x1;k<x2;k++)
            {
                Map[j][k]++;
            }
        }
    }

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            A=0;
            if(visited[i][j]==1||Map[i][j]>0)continue;
            DFS(i,j);
            num++;
            AV.push_back(A);
        }
    }

    sort(AV.begin(),AV.end());

    cout<<num<<'\n';
    for(int i=0;i<AV.size();i++)
    {
        cout<<AV[i]<<' ';
    }
    return 0;
}