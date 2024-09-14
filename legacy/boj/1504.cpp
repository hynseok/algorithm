#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int N, E;
vector<pair<int,int> > graph[8001];
int d[3][8001];

void dijkstra(int start, int n) {
  priority_queue<pair<int,int> > pq;
  pq.push(make_pair(0, start));
  d[n][start] = 0;

  while(!pq.empty()) {
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(d[n][now] < dist) 
      continue;
    
    for(int i = 0; i < graph[now].size(); i++) {
      int cost = dist + graph[now][i].second;

      if(cost < d[n][graph[now][i].first]) {
        d[n][graph[now][i].first] = cost;
        pq.push(make_pair(-cost, graph[now][i].first));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> E;

  int a, b, c;
  for(int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
  }

  for(int i = 0; i <= N; i++) {
    d[0][i] = INF;
    d[1][i] = INF;
    d[2][i] = INF;
  }
  dijkstra(1,0);

  int v1, v2;
  cin >> v1 >> v2;
  dijkstra(v1,1);
  dijkstra(v2,2);

  int ans = min(d[0][v1]+d[1][v2]+d[2][N],d[0][v2]+d[2][v1]+d[1][N]);
  if(ans >= INF) cout << "-1\n";
  else cout << ans << "\n";
}