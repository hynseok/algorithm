#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

priority_queue <pair<int,int>> label;
vector <pair<int,int>> Graph[20001];
int dist[20001];
int v, e, k;

void dijkstra(int start){
    dist[start] = 0;

    label.push({0, start});

    while(!label.empty()){
        int cost = -label.top().first;
        int node = label.top().second;
        label.pop();

        if(dist[node] < cost) continue;

        for(int i=0; i<Graph[node].size(); i++){
            int next = Graph[node][i].first;
            int nextCost = cost + Graph[node][i].second;

            if(dist[next] >  nextCost){
                dist[next] = nextCost;
                label.push({-nextCost, next});
            }

        }
    }

    return;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<20001; i++){
        dist[i] = INF;
    }

    cin>>v>>e;
    cin>>k;

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        Graph[u].push_back({v, w});
    }

    dijkstra(k);

    for(int i=1; i<=v; i++){
        if(dist[i] == INF) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }

    return 0;  
}