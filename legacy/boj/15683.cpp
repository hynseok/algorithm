#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int N, M;
int map_arr[9][9];
int ans = INF;
vector<pair<int, pair<int, int> > > cctv_stack;

void see(int type, int direction, int y, int x) {
  switch(type) {
    case 1: 
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
      } else if(direction == 1) {
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 2) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
      } else if(direction == 3) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      }
      break;
    case 2: 
      if(direction % 2 == 0) {
          for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
      } else if(direction % 2 == 1) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      }
      break;
    case 3: 
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 1) {
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
      } else if(direction == 2) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 3) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
      }
      break;
    case 4:
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 1) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 2) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      } else if(direction == 3) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]--;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]--;
        }
      }
      break;
    case 5: 
      for(int i = x + 1; i < M; i++) {
        if(map_arr[y][i] == 6) break;
        if(map_arr[y][i] > 0) continue;
        map_arr[y][i]--;
      }
      for(int i = x - 1; i >= 0; i--) {
        if(map_arr[y][i] == 6) break;
        if(map_arr[y][i] > 0) continue;
        map_arr[y][i]--;
      }
      for(int i = y - 1; i >= 0; i--) {
        if(map_arr[i][x] == 6) break;
        if(map_arr[i][x] > 0) continue;
        map_arr[i][x]--;
      }
      for(int i = y + 1; i < N; i++) {
        if(map_arr[i][x] == 6) break;
        if(map_arr[i][x] > 0) continue;
        map_arr[i][x]--;
      }
      break;
  }
}

void reset_see(int type, int direction, int y, int x) {
  switch(type) {
    case 1: 
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
      } else if(direction == 1) {
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 2) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
      } else if(direction == 3) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      }
      break;
    case 2: 
      if(direction % 2 == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
      } else if(direction % 2 == 1) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      }
      break;
    case 3: 
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 1) {
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
      } else if(direction == 2) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 3) {
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
      }
      break;
    case 4:
      if(direction == 0) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 1) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 2) {
        for(int i = x + 1; i < M; i++) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      } else if(direction == 3) {
        for(int i = x - 1; i >= 0; i--) {
          if(map_arr[y][i] == 6) break;
          if(map_arr[y][i] > 0) continue;
          map_arr[y][i]++;
        }
        for(int i = y - 1; i >= 0; i--) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
        for(int i = y + 1; i < N; i++) {
          if(map_arr[i][x] == 6) break;
          if(map_arr[i][x] > 0) continue;
          map_arr[i][x]++;
        }
      }
      break;
    case 5: 
      for(int i = x + 1; i < M; i++) {
        if(map_arr[y][i] == 6) break;
        if(map_arr[y][i] > 0) continue;
        map_arr[y][i]++;
      }
      for(int i = x - 1; i >= 0; i--) {
        if(map_arr[y][i] == 6) break;
        if(map_arr[y][i] > 0) continue;
        map_arr[y][i]++;
      }
      for(int i = y - 1; i >= 0; i--) {
        if(map_arr[i][x] == 6) break;
        if(map_arr[i][x] > 0) continue;
        map_arr[i][x]++;
      }
      for(int i = y + 1; i < N; i++) {
        if(map_arr[i][x] == 6) break;
        if(map_arr[i][x] > 0) continue;
        map_arr[i][x]++;
      }
      break;
  }
}

void dfs() {
  if(cctv_stack.empty()) {
    int blind = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(map_arr[i][j] == 0) 
          blind++;
      }
    }
    ans = min(ans, blind);
    return;
  }
  pair<int, pair<int, int> > top;
  top = cctv_stack.back();
  cctv_stack.pop_back();

  for(int i = 0; i < 4; i++) {
    see(top.first, i, top.second.first, top.second.second);
    dfs();
    reset_see(top.first, i, top.second.first, top.second.second);
  }

  cctv_stack.push_back(top);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> map_arr[i][j];
      if(map_arr[i][j] > 0 && map_arr[i][j] != 6) {
        cctv_stack.push_back(make_pair(map_arr[i][j], make_pair(i,j)));
      }
    }
  }

  dfs();
  cout << ans << "\n";
}