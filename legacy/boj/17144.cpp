#include <bits/stdc++.h>

using namespace std;

int r, c, t;
int room[51][51];
int diff[51][51];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int clean = 0;
int found = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> r >> c >> t;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> room[i][j];
      if(room[i][j] == -1 && found == 0){
        clean = i;
        found = 1;
      }
    }
  }

  for(int k = 0; k < t; k++) {
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        diff[i][j] = 0;
      }
    }
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(room[i][j] != 0 && room[i][j] != -1) {
          int cnt = 0;
          for(int l = 0; l < 4; l++) {
            int ny = i + dy[l];
            int nx = j + dx[l];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(room[ny][nx] == -1) continue;
            diff[ny][nx] += room[i][j] / 5;
            cnt++;
          }
          diff[i][j] -= cnt * (room[i][j]/5);
          cnt = 0;
        }
      }
    }
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        room[i][j] += diff[i][j];
      }
    }

    for(int i = clean-1; i >= 0; i--) {
      if(room[i+1][0]!=-1)
        room[i+1][0] = room[i][0];
    }
    for(int i = clean+2; i < r; i++) {
      if(room[i-1][0]!=-1)
        room[i-1][0] = room[i][0];
    }
    for(int i = 1; i < c; i++) {
      room[0][i-1] = room[0][i];
      room[r-1][i-1] = room[r-1][i];
    }
    for(int i = 1; i <= clean; i++) {
      room[i-1][c-1] = room[i][c-1];
    }
    for(int i = r-2; i >= clean+1; i--) {
      room[i+1][c-1] = room[i][c-1];
    }
    for(int i = c-2; i > 0; i--) {
      room[clean][i+1] = room[clean][i];
      room[clean+1][i+1] = room[clean+1][i];
    }
    room[clean][1] = 0;
    room[clean+1][1] = 0;
  }

  int ans = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(room[i][j] != -1)
        ans += room[i][j];
    }
  }
  cout << ans;
}