#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC, N, M, W, S, E, T;
	int INF = 987654321;
	int dist[501][501];
	
	cin >> TC;

	while(TC){
		cin >> N >> M >> W;
		
		for(int i=0; i<=N; i++){
			for(int j=0; j<=N; j++){
				dist[i][j] = INF;
			}
		}
		for(int i=0; i<=N; i++){
			dist[i][i] = 0;
		}

		for(int i=0; i<M; i++){
			cin >> S >> E >> T;	
			if(T < dist[S-1][E-1]){
				dist[S-1][E-1] = T;
				dist[E-1][S-1] = T;
			}
		}

		for(int i=0; i<W; i++){
			cin >> S >> E >> T;
			dist[S-1][E-1] = -T;
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<N; k++){
					int t = dist[i][k] + dist[k][j];
					if(t<dist[i][j])
						dist[i][j] = t;
				}
			}
		}

		int flag = 0;

		for(int i=0; i<N; i++){
			if(dist[i][i]<0) flag = 1;
		}

		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";

		TC--;
	}

		
}

