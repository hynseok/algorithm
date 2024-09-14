#include <bits/stdc++.h>
using namespace std;
int V, E, Fidx1, Fidx2, idx1, idx2;
int ret1, ret2;
vector<int> v[10001];
int parent[10001];
int level[10001];
int visited[10001];
int T;
void vclear(){
    for(int i=0;i<10001;i++){
        while(!v[i].empty()) v[i].pop_back();
    }
    return;
}
void Set(int node, int prev){
    parent[node] = prev;
    level[node] = level[prev] + 1;

    for(int i=0;i<v[node].size();i++){
        int child = v[node][i];
        if(child==prev)continue;
        Set(child,node);
    }
}
void nodeN(int a){
    visited[a]=1;

    for(int i=0;i<v[a].size();i++)
    {
        int next = v[a][i];
        if(parent[a]==next||visited[next]) continue;
        nodeN(next);
    }
    return;
}
void Find(int a, int b){
    ret2 = 0;
    if(level[a]<level[b]) swap(a,b);

    while(level[a]!=level[b]){
        a = parent[a];
    }

    while(a!=b){
        a=parent[a];
        b=parent[b];
    }
    ret1 = a;
    nodeN(ret1);
    for(int i=0;i<10001;i++){
        if(visited[i]==1)ret2++;
    }
    return;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int i=1;i<=T;i++){
        vclear();
        memset(parent,0,sizeof(parent));
        memset(level,0,sizeof(level));
        memset(visited,0,sizeof(visited));
        cin>>V>>E>>Fidx1>>Fidx2;
        for(int j=0;j<E;j++){
            cin>>idx1>>idx2;
            v[idx1].push_back(idx2);
            v[idx2].push_back(idx1);
        }
        Set(1,0);
        Find(Fidx1,Fidx2);
        cout<<"#"<<i<<" "<<ret1<<' '<<ret2<<'\n';
    }
    return 0;
}
