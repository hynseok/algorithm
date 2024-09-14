#include <bits/stdc++.h>
using namespace std;

int visited[51];
int N,del;
vector<int> V[54];

int findleaf(int start)
{
    visited[start] = 1;

    int ret = 0;
    int child = 0;

    for(int i=0;i<V[start].size();i++)
    {
        int next = V[start][i];
        if(visited[next]==1||next==del) continue;
        ret += findleaf(next);
        child++;
    }

    if(child==0) return 1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int root;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int idx;
        cin>>idx;
        if(idx==-1) root = i;
        else V[idx].push_back(i);
    }

    cin>>del;
    
    if(del==root) cout<<0<<'\n';
    else cout<<findleaf(root)<<'\n';

    return 0;
}