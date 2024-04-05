#include <bits/stdc++.h>
using namespace std;

int Map[1001][1001] = {0, };
int visited[1001]= {0, };
int N, M;

void dfs(int idx)
{
    visited[idx] = 1;
    for(int i=1;i<=N;i++)
    {
        if(!visited[i]&&Map[idx][i]==1)
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    cin >> N >> M;

    for(int i=0;i<M;i++)
    {
        int a, b;  
        cin >> a >> b;
        Map[a][b] = Map[b][a] = 1;
    }

    for(int i=1;i<=N;i++)
    {
        if(!visited[i]  )
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}