#include <bits/stdc++.h>
using namespace std;

int n, m;
int matrix[1001][1001];
int visited[1001][1001][2];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

struct position
{
  int y;
  int x;
  bool wall;
};

int bfs()
{
  queue<position> Q;
  visited[0][0][0] = 1;
  Q.push({0, 0, 0});

  while (!Q.empty())
  {
    position curr = Q.front();
    Q.pop();

    if (curr.y == n - 1 && curr.x == m - 1)
      return visited[curr.y][curr.x][curr.wall];

    for (int i = 0; i < 4; i++)
    {
      position next;
      next.y = curr.y + dy[i];
      next.x = curr.x + dx[i];
      next.wall = curr.wall;
      if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m)
        continue;
      if (visited[next.y][next.x][curr.wall])
        continue;

      if (matrix[next.y][next.x] == 0)
      {
        visited[next.y][next.x][next.wall] = visited[curr.y][curr.x][curr.wall] + 1;
        Q.push({next.y, next.x, curr.wall});
      }
      if (matrix[next.y][next.x] == 1 && next.wall == 0)
      {
        visited[next.y][next.x][1] = visited[curr.y][curr.x][curr.wall] + 1;
        next.wall = 1;
        Q.push(next);
      }
    }
  }
  return -1;
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string S;
    cin >> S;
    for (int j = 0; j < m; j++)
    {
      matrix[i][j] = S[j] - '0';
    }
  }
  cout << bfs();
}