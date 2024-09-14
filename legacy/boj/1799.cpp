#include <bits/stdc++.h>

using namespace std;

int N;
int ans[2];
int _map[11][11];
int l[20];
int r[20];

void back_track(int row, int col, int count, int color) {
  if(col >= N) {
    row++;
    if(col % 2 == 0) col = 1;
    else col = 0;
  }
  if(row >= N) {
    ans[color] = max(ans[color], count);
    return;
  }

  if(_map[row][col] && !l[col - row + N - 1] && !r[row + col]) {
    l[col - row + N - 1] = r[row + col] = 1;
    back_track(row, col + 2, count + 1, color);
    l[col - row + N - 1] = r[row + col] = 0;
  }
  back_track(row, col + 2, count, color);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0;j < N; j++) {
      cin >> _map[i][j];
    }
  }

  back_track(0, 0, 0, 0);
  back_track(0, 1, 0, 1);

  cout << ans[0] + ans[1];
}