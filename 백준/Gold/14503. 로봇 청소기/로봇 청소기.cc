#include <bits/stdc++.h>

using namespace std;

typedef struct robot {
	int r;
	int c;
	int dir; // 0 n, 1 e, 2 s, 3 w 
} robot;

int field[51][51]; // 0 not cleaned, 1 wall, 2 cleaned

int main() {
	int ans = 0;
	int n, m;
	robot r;
	
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};

	cin >> n >> m;
	cin >> r.r >> r.c >> r.dir;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}

	while(true) {
		if(field[r.r][r.c] == 0) {
			field[r.r][r.c] = 2; // clean
			ans++;
		}

		bool flag = false;
		for(int i = 0; i < 4; i++) {
			int nextr, nextc;
			nextr = r.r + dy[i];
			nextc = r.c + dx[i];
			if(nextr < 0 || nextr >= n || nextc < 0 || nextc >= m) {continue;}
			if(field[nextr][nextc] == 0) {
				flag = true;
				break;
			}
		}

		if(flag) {
			r.dir -= 1;
			if(r.dir == -1) { r.dir = 3; }
			int nextr, nextc;
			nextr = r.r + dy[r.dir];
			nextc = r.c + dx[r.dir];
			if(nextr < 0 || nextr >= n || nextc < 0 || nextc >= m) {continue;}
			if(field[nextr][nextc] == 0) {
				r.r = nextr;
				r.c = nextc;
			} else {
				continue;
			}
		} else {
			int nextr, nextc, nextdir;
			nextr = r.r + dy[(r.dir + 2) % 4];
			nextc = r.c + dx[(r.dir + 2) % 4];
			if(nextr < 0 || nextr >= n || nextc < 0 || nextc >= m) {continue;}
			if(field[nextr][nextc] == 0 || field[nextr][nextc] == 2) {
				r.r = nextr;
				r.c = nextc;
				continue;
			} else {
				// stop the robot
				break; 
			}
		}
	}

	cout << ans;

}
