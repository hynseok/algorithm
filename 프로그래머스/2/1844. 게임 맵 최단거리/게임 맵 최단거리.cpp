#include<vector>
#include<queue>
using namespace std;

typedef struct {
    int y;
    int x;
    int dist;
} state;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[101][101] = {0, };

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    queue<state> q;

    q.push({0,0,0});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        state now;
        now = q.front();
        q.pop();
        now.dist++;
        
        if(now.y == n-1 && now.x == m-1) {
            answer = now.dist;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            
            if(visited[ny][nx] == 0 && maps[ny][nx] == 1) {
                visited[ny][nx] = 1;
                q.push({ny, nx, now.dist});
            }
        }
    }
    
    if(visited[n-1][m-1] == 0) answer = -1;
    
    return answer;
}