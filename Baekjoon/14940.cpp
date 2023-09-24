#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0};

void bfs( int y, int x ) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
    
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx] >= 1 || arr[ny][nx] == 0) continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x, y;

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2){
              y = i;
              x = j;
            }
        }
    }

    bfs( y, x );

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0) cout<<0<<" ";
            else if(arr[i][j] == 2) cout<<0<<" ";
            else cout<<visited[i][j]-1<<" ";
        }
        cout<<"\n";
    }
  
    return 0;
}