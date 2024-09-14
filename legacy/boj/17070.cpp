#include <bits/stdc++.h>
using namespace std;

int Map[17][17];
int N, ans=0;
struct Pipe
{
    int direction; //1가로 2대각선 3세로
    vector<pair<int,int>> index; //y x
};
vector<Pipe> road;

void DFS()
{
    Pipe now = road.back();
    int nowy = now.index.back().first;
    int nowx = now.index.back().second;
    int nowd = now.direction;
    if(nowy==N&&nowx==N)
    {
        ans++;
        return;
    }
    
    if(nowd==1)
    {
        if(nowx+1<=N&&Map[nowy][nowx+1]==0)
        {
            Pipe temp;
            temp.direction=1;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy,nowx+1});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
        if(nowy+1<=N&&nowx+1<=N&&Map[nowy][nowx+1]==0&&Map[nowy+1][nowx]==0&&Map[nowy+1][nowx+1]==0)
        {
            Pipe temp;
            temp.direction=2;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy,nowx+1});
            temp.index.push_back({nowy+1,nowx});
            temp.index.push_back({nowy+1,nowx+1});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
    }

    if(nowd==2)
    {
        if(nowx+1<=N&&Map[nowy][nowx+1]==0)
        {
            Pipe temp;
            temp.direction=1;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy,nowx+1});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
        if(nowy+1<=N&&Map[nowy+1][nowx]==0)
        {
            Pipe temp;
            temp.direction=3;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy+1,nowx});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
        if(nowy+1<=N&&nowx+1<=N&&Map[nowy][nowx+1]==0&&Map[nowy+1][nowx]==0&&Map[nowy+1][nowx+1]==0)
        {
            Pipe temp;
            temp.direction=2;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy,nowx+1});
            temp.index.push_back({nowy+1,nowx});
            temp.index.push_back({nowy+1,nowx+1});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
    }

    if(nowd==3)
    {
        if(nowy+1<=N&&Map[nowy+1][nowx]==0)
        {
            Pipe temp;
            temp.direction=3;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy+1,nowx});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
        if(nowy+1<=N&&nowx+1<=N&&Map[nowy][nowx+1]==0&&Map[nowy+1][nowx]==0&&Map[nowy+1][nowx+1]==0)
        {
            Pipe temp;
            temp.direction=2;
            temp.index.push_back({nowy,nowx});
            temp.index.push_back({nowy,nowx+1});
            temp.index.push_back({nowy+1,nowx});
            temp.index.push_back({nowy+1,nowx+1});
            road.push_back(temp);
            DFS();
            road.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> Map[i][j];
        }
    }

    Pipe start;
    start.direction=1;
    start.index.push_back({1,1});
    start.index.push_back({1,2});
    road.push_back(start);
    DFS();
    cout<<ans;
}