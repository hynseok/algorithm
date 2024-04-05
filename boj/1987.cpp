#include <bits/stdc++.h>
using namespace std;

char board[21][21];
int visited[27];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int ans = 0;
int R, C;

void search(int y, int x, int cnt){
    if(ans<cnt) ans = cnt;

    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if(ny<0||ny>=R||nx<0||nx>=C) continue;
        int next = (int)(board[ny][nx]-'A');
        if(visited[next]==0){
            visited[next] = 1;
            search(ny,nx,cnt+1);
            visited[next] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
        }
    }

    visited[(int)board[0][0]-'A'] = 1;
    search(0,0,1);

    cout<<ans<<'\n';

    return 0;
}