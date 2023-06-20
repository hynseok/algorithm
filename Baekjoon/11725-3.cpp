#include <bits/stdc++.h>
using namespace std;
#define MAX 100001




int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans[MAX];
    vector<int> Map[MAX];
    queue<int> Q;
    int visited[MAX] = {0, };

    int N;
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int a, b;
        cin>>a>>b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }

    Q.push(1);
    visited[1]=1;

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for(int i=0;i<Map[node].size();i++)
        {
            if(visited[Map[node][i]]==0)
            {
                Q.push(Map[node][i]);
                visited[Map[node][i]]=1;
                ans[Map[node][i]] = node;
            }
        }
    }

    for(int i=2;i<=N;i++)
    {
        cout<<ans[i]<<'\n';
    }
}