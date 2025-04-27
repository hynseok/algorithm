#include <iostream>

#define INF 99999999

typedef struct edge {
  int src;
  int dst;
  int w;
} edge;

typedef long long ll;

using namespace std;

edge earr[6001];
ll dist[502];

int main() {
  int N, M;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    edge e;
    cin >> e.src >> e.dst >> e.w;
    earr[i] = e;
  }

  for(int i = 0; i < N + 1; i++) {
    dist[i] = INF;
  }

  dist[1] = 0;
  for(int i = 1; i < N + 1; i++) {
    for(int j = 0; j < M; j++) {
      edge e = earr[j];
      if(dist[e.src] == INF) continue;
      ll next = dist[e.src] + e.w;
      if(next < dist[e.dst]) {
        dist[e.dst] = next;
        if(i == N) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  for(int i = 2; i < N + 1; i++) {
    ll ans = dist[i] == INF ? -1 : dist[i];
    cout << ans << "\n";
  }

  return 0;
}