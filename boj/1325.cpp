#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> credit[10004];
int visited[10004];


int dfs(int start)
{
    int ret=1;
    int tok=0;
    visited[start] = 1;

    for(int i=0;i<credit[start].size();i++)
    {
        int next = credit[start][i];
        if(visited[next]==1)continue;
        ret+=dfs(next);
        tok++;
    }
     
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> anss;
    int a,b;
    int ans = -1;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        credit[b].push_back(a);
    }

    for(int i=1;i<=N;i++)
    {
        fill(visited,visited+10004,0);

        int temp = dfs(i);
        if(ans<temp)
        {
            ans=temp;
            anss.clear();
            anss.push_back(i);
        }
        else if(ans==temp)
        {
            anss.push_back(i);
        }

    }

    for(int i=0;i<anss.size();i++)
    {
        cout<<anss[i]<<' ';
    }


    return 0;
}