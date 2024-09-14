#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 가로, 세로 칸수
int n, m;

/**
 * 입력을 정수형으로 추상화 
 * 0: .
 * 1: #
 * 2: O
 * */ 
int map[11][11];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

typedef struct coor {
  int x;
  int y;
};
coor candy_coor[2]; // 사탕의 좌표를 저장. 0: Red, 1: Blue.
coor hole_coor; // 구멍의 좌표

int is_hole[2] = {0, }; // 0: Red, 1: Blue.

int roll(coor &red, coor &blue, int d) {
  while(1) {
    int curr_red = map[red.y][red.x];
    int curr_blue = map[blue.y][blue.x];
    if(curr_red == 1) {
      blue.y += dy[d];
      blue.x += dx[d];
    } else if (curr_blue == 1) {
      red.y += dy[d];
      red.x += dx[d]; 
    } else if (curr_red == 1 && curr_blue == 1){
      break;
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  cin >> n >> m;
  
  string line;
  for(int i = 0; i < n; i++) {
    cin >> line;
    for(int j = 0; j < m; j++) {
      char c = line[j];
      if(c == '#') {
        map[i][j] = 1;
      }
      else if(c == 'O') {
        map[i][j] = 2;
        hole_coor.y = i;
        hole_coor.x = j;
      }
      else {
        map[i][j] = 0;
        if(c == 'R') {
          candy_coor[0].y = i;
          candy_coor[0].x = j;
        } else if (c == 'B') {
          candy_coor[1].y = i;
          candy_coor[1].x = j;
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << map[i][j];
    }
    cout << '\n';
  }

}