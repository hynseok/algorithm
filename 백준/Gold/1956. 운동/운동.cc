#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    
    int dist[401][401];
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int min_cycle = 1e9;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i != j && dist[i][j] != 1e9 && dist[j][i] != 1e9) {
                min_cycle = min(min_cycle, dist[i][j] + dist[j][i]);
            }
        }
    }
    
    if (min_cycle == 1e9) {
        cout << -1 << "\n";
    } else {
        cout << min_cycle << "\n";
    }
    
    return 0;
}