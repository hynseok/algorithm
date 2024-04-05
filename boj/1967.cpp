#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool visited[10001];

int max_length = 0;
int deep_node = 1;

void dfs(int node, int length)
{
  visited[node] = true;
  if (max_length < length)
  {
    max_length = length;
    deep_node = node;
  }

  for (int i = 0; i < tree[node].size(); i++)
  {
    int next_node = tree[node][i].first;
    int next_length = length + tree[node][i].second;

    if (visited[next_node])
      continue;

    dfs(next_node, next_length);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int parent, child, weight;

  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    cin >> parent >> child >> weight;
    tree[parent].push_back({child, weight});
    tree[child].push_back({parent, weight});
  }

  dfs(1, 0);

  memset(visited, false, sizeof(visited));

  dfs(deep_node, 0);

  cout << max_length;

  return 0;
}