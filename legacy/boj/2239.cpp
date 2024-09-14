#include <bits/stdc++.h>
using namespace std;

int puzzle[10][10];
vector<pair<int, int> > points;

int is_possible(int y, int x, int n) {
  for(int i = 1; i <= 9; i++) {
    if(puzzle[y][i] == n) {
      return 0;
    }
    if(puzzle[i][x] == n) {
      return 0;
    }
  }

  int ny = (y - 1) / 3 * 3 + 1;
  int nx = (x - 1) / 3 * 3 + 1;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(puzzle[ny + i][nx + j] == n) {
        return 0;
      }
    }
  }

  return 1;
}

void dfs(int count) {
  if(count == points.size()) {
    for(int i = 1; i <= 9; i++) {
      for(int j = 1; j <= 9; j++) {
        cout << puzzle[i][j];
      }
      cout << "\n";
    }
    exit(0);
  }

  int y, x;
  y = points[count].first;
  x = points[count].second;

  for(int i = 1; i <= 9; i++) {
    if(is_possible(y, x, i)) {
      puzzle[y][x] = i;
      dfs(count + 1);
      puzzle[y][x] = 0;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string s;

  for(int i = 1; i <= 9; i++) {
    cin >> s;
    for(int j = 1; j <= 9; j++) {
      puzzle[i][j] = s[j-1] - '0';
      if(puzzle[i][j] == 0) {
         points.push_back(make_pair(i,j));
      }          
    }
  }

  dfs(0);  

  return 0;
}