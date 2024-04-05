#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V;
int List[9];
int visited[9];

void DFS(int cnt)
{
    if(cnt==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<V[i]<<' ';
        }
        cout<<'\n';
    }

    for(int i=0;i<N;i++)
    {
        if(visited[i]==1) continue;
        if(!V.empty())
        {
            if(V.back()>List[i]) continue;
        }
        V.push_back(List[i]);
        visited[i] = 1;
        DFS(cnt+1);
        visited[i] = 0;
        V.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>List[i];
    }

    sort(List,List+N);
    DFS(0);

    return 0;
}