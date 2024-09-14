#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int Map[101][101];
int visited[101][101];
int dp[101][101];
string line;
int N;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int ans = 0;
        memset(Map,0,sizeof(Map));
        memset(visited,0,sizeof(visited));
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>line;
            for(int j=0;j<N;j++){
                Map[i][j] = line[j]-'0';
            }
        }

        queue<pair<int,int> > Q;
        Q.push({0,0});
        visited[0][0] = 1;
        dp[0][0] = 0;
        while(!Q.empty()){
            int cx = Q.front().first;
            int cy = Q.front().second;
            Q.pop();

            for(int i=0;i<4;i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx<0||nx>=N||ny<0||ny>=N) continue;
                
                if(visited[nx][ny]==0||dp[nx][ny] > dp[cx][cy] + Map[nx][ny]){
                    dp[nx][ny] = dp[cx][cy] + Map[nx][ny];
                    visited[nx][ny]=1;
                    Q.push({nx,ny});
                }

            }
        }

        cout<<'#'<<tc<<' '<<dp[N-1][N-1]<<'\n';

    }
    return 0;
}