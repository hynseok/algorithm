#include <bits/stdc++.h>
using namespace std;

int N;
char Map[301][301];
int visited[301][301];
int dy[8] = {0,0,1,-1,1,1,-1,-1};
int dx[8] = {1,-1,0,0,1,-1,1,-1};

int find(int cy, int cx){
    int ny, nx;
    int flag = 0;
    for(int i=0;i<8;i++){
        ny = cy + dy[i];
        nx = cx + dx[i];
        if(ny<0||ny>N-1||nx<0||nx>N-1)continue;
        if(Map[ny][nx]=='*')flag++;
    }
    return flag;
}

void dfs(int cy, int cx){
    for(int i=0;i<8;i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(visited[ny][nx]||ny<0||ny>N-1||nx<0||nx>N-1) continue;
        visited[ny][nx] = 1;
        if(find(ny,nx)==0)dfs(ny,nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    int ans = 0;
    for(int tc=1;tc<=T;tc++){
        ans = 0;
        memset(visited,0,sizeof(visited));
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>Map[i][j];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j]==0&&Map[i][j]=='.'){
                    if(find(i,j)==0){
                        visited[i][j]=1;
                        dfs(i,j);
                        ans++;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j]==0&&Map[i][j]=='.')ans++;
            }
        }

        cout<<'#'<<tc<<' '<<ans<<'\n';
    }

    return 0;
}