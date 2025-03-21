#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[20001];

int solution(int n, vector<vector<int>> edge) {    
    int answer = 0;
    
    queue<int> q;
    
    q.push(1);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < edge.size(); i++) {
            int src = edge[i][0];
            int dest = edge[i][1];
            if(src == node && dist[dest] == 0) {
                dist[dest] = dist[src] + 1;
                q.push(dest);
            } else if (dest == node && dist[src] == 0) {
                dist[src] = dist[dest] + 1;
                q.push(src);
            }
        }
    }
    
    
    int max = 0;
    for(int i = 2; i <= n; i++) {
        if(max < dist[i]) {
            max = dist[i];
            answer = 1;
        } else if(max == dist[i]) {
            answer++;
        }
    }
    
    return answer;
}