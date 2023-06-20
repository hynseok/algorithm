#include <bits/stdc++.h>
using namespace std;

int ans;
int visited[1001];
int Map[1001];

void dfs(int now, int start)
{
    if(visited[now]==1) return;

    visited[now] = 1;
    int next = Map[now];
    if(next==start)
    {
        ans++;
        return;
    }
    dfs(next,start);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   

    int T;
    cin>>T;
    for(int q=0;q<T;q++)
    {
        int N;
        for(int i=0;i<1001;i++)
        {
            Map[i] = 0;
            visited[i] = 0;
        }
        ans = 0;

        cin>>N;
        int k;
        for(int i=1;i<=N;i++)
        {
            cin>>k;
            Map[i] = k;
        }

        for(int i=1;i<=N;i++)
        {
            dfs(i,i);
        }
        cout<<ans<<'\n';
    }

    return 0;
}