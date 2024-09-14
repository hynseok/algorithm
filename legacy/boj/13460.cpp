#include <bits/stdc++.h>

using namespace std;

typedef struct step {
	int ry, rx;
	int by, bx;
	int count;
} step;

int N, M;
int ans = 11;

// 0: wall, 1: red, 2: blue, 3: hole
int Map[11][11];
int visited[11][11][11][11];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

//d: direction, 0: up, 1: right, 2: down, 3: left
int move(int& ry, int& rx, int& by, int&bx, int d) {
	int rbdist = 0;
	int bbdist = 0;
	int rbflag = 0;
	int bbflag = 0;

	while(Map[ry+dy[d]][rx+dx[d]] != 0){
		ry += dy[d];
		rx += dx[d];
		rbdist++;
		if(Map[ry][rx] == 3) {
			rbflag = 1;
			break;
		}
	}
	
	while(Map[by+dy[d]][bx+dx[d]] != 0){
		by += dy[d];
		bx += dx[d];
		bbdist++;
		if(Map[by][bx] == 3) {
			bbflag = 1;
			break;
		}
	}

	if(rx == bx && ry == by) {
		if(rbflag&&bbflag)
			return -1;
		if(rbdist > bbdist) ry -= dy[d], rx -= dx[d];
		else by -= dy[d], bx -= dx[d];
	}
	if(bbflag) return -1;
	if(rbflag) return 1;

	return 0;
}

void bfs(int ry, int rx, int by, int bx){
	queue<step> q;
	step fstep;
	fstep.ry = ry;
	fstep.rx = rx;
	fstep.by = by;
	fstep.bx = bx;
	fstep.count = 0;
	q.push(fstep);
	visited[ry][rx][by][bx] = 1;

	while(!q.empty()) {
		step curstep = q.front();
		q.pop();
		if(curstep.count>=10) 
			break;
		
		for(int i=0; i<4; i++) {
			step nextstep;
			nextstep.ry = curstep.ry;
			nextstep.rx = curstep.rx;
			nextstep.by = curstep.by;
			nextstep.bx = curstep.bx;
			nextstep.count = curstep.count + 1;
				
			int ret = move(nextstep.ry, nextstep.rx, nextstep.by, nextstep.bx, i);
 
			if(ret == -1) continue;
			if(ret == 1){
				cout << nextstep.count;
				return;
			}
			
			if(visited[nextstep.ry][nextstep.rx][nextstep.by][nextstep.bx]) continue;
			visited[nextstep.ry][nextstep.rx][nextstep.by][nextstep.bx] = 1;
			q.push(nextstep);
		}

	}
	cout << -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	int ry, rx, by, bx;
	char input;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> input;
			if(input == '#')
				Map[i][j] = 0;
			if(input == 'O')
				Map[i][j] = 3;
			if(input == 'R'){
				Map[i][j] = 1;
				ry = i; rx = j;
			}
			if(input == 'B'){
				Map[i][j] = 2;
				by = i; bx = j;
			}
			if(input == '.')
				Map[i][j] = 4;
		}
	}
	bfs(ry, rx, by, bx);
}
