#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

int n, m;
int matrix[101][101];

void floyd()
{
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {

        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // initialization
  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++)
    {
      matrix[i][j] = INF;
      if (i == j)
        matrix[i][j] = 0;
    }
  }

  cin >> n >> m;

  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    if (matrix[a][b] > c)
      matrix[a][b] = c;
  }

  floyd();

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (matrix[i][j] == INF)
      {
        cout << 0 << " ";
      }
      else
      {
        cout << matrix[i][j] << " ";
      }
    }
    cout << '\n';
  }

  return 0;
}