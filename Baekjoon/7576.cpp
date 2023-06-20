#include <bits/stdc++.h>
using namespace std;

int Map[1001][1001];
queue<pair<int,int>> q;
int M, N, result = 0;


void bfs()
{
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(x+1>=0&&x+1<M)
        {
            if(Map[y][x+1]==0)
            {
                Map[y][x+1]=Map[y][x]+1;
                q.push(make_pair(y,x+1));
            }
        }
        if(x-1>=0&&x-1<M)
        {
            if(Map[y][x-1]==0)
            {
                Map[y][x-1]=Map[y][x]+1;
                q.push(make_pair(y,x-1));
            }
        }
        if(y+1>=0&&y+1<N)
        {
            if(Map[y+1][x]==0)
            {
                Map[y+1][x]=Map[y][x]+1;
                q.push(make_pair(y+1,x));
            }
        }
        if(y-1>=0&&y-1<N)
        {
            if(Map[y-1][x]==0)
            {
                Map[y-1][x]=Map[y][x]+1;
                q.push(make_pair(y-1,x));
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>M>>N;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int temp;
            cin>>temp;
            if(temp==1)
            {
                q.push(make_pair(i,j));
            }
            Map[i][j]=temp;
        }
    }

    bfs();



    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Map[i][j]==0)
            {
                cout<<-1;
                return 0;
            }
            if(result<Map[i][j])
                result = Map[i][j];
        }
    }

    cout<<result-1;
    return 0;
}