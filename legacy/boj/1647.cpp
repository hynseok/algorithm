#include <bits/stdc++.h>

using namespace std;

int N;
int M;

int parent[100001];
vector<pair<pair<int,int>, int> > edges;

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
  return a.second < b.second;
}

int find(int n) {
  if(parent[n] != n)
    parent[n] = find(parent[n]);
  return parent[n];
}

void _union(int a, int b) {
  a = find(a);
  b = find(b);

  if (a < b) 
    parent[b] = a;
  else
    parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int ans = 0;
  int last = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    parent[i] = i;
  }

  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    edges.push_back(make_pair(make_pair(a,b),c));
  }

  sort(edges.begin(), edges.end(), cmp);

  for (int i = 0; i < edges.size(); i++) {
    if(find(edges[i].first.first) != find(edges[i].first.second)) {
      _union(edges[i].first.first,edges[i].first.second);
      ans += edges[i].second;
      last = edges[i].second;
    }
  }

  cout << ans - last << "\n";
}