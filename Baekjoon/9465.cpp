#include <bits/stdc++.h>
using namespace std;

int N, M;
int Map[50][50];
int ans = 987654321;
vector<pair<int,int>> House, Chicken, V;
int Select[13];

int calDistance()
{
    int sum = 0;
    for(int i=0;i<House.size();i++)
    {
        int y = House[i].first;
        int x = House[i].second;
        int d = 987654321;

        for(int j=0;j<V.size();j++)
        {
            int yy = V[j].first;
            int xx = V[j].second;
            
            int dist = abs(yy-y) + abs(xx-x);
            d = min(dist, d);
        }

        sum += d;

    }

    return sum;
}

void DFS(int now, int cnt)
{
    if(cnt == M)
    {
        ans = min(ans, calDistance());
        return ;
    }

    for(int i=now;i<Chicken.size();i++)
    {
        if(Select[i]==1) continue;
        Select[i] = 1;
        V.push_back(Chicken[i]);
        DFS(i,cnt+1);
        V.pop_back();
        Select[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> Map[i][j];
            if(Map[i][j]==1) House.push_back({i,j});
            if(Map[i][j]==2) Chicken.push_back({i,j});
        }
    }

    DFS(0,0);
    cout<<ans;
}