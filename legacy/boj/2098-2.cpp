#include <bits/stdc++.h>
#define FOR(i, N) for(int i=0; i<N; i++)
#define INF 987654321
using namespace std;

int N;
int dist[16][16];
int dp[16][1<<16];

int find(int cur, int visit) {
	if(visit == (1<<N) -1){
		if(dist[cur][0] == 0)
			return INF;
		return dist[cur][0];
	}

	if(dp[cur][visit] != -1)
		return dp[cur][visit];
	
	dp[cur][visit] = INF;	
	
	FOR(i, N) {
		if(dist[cur][i] == 0)
			continue;
		if((visit & (1 << i)) == (1 << i))
			continue;
		dp[cur][visit] = min(dp[cur][visit], dist[cur][i] + find(i, visit | (1 << i)));
	}
	
	return dp[cur][visit];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	FOR(i, N) {
		FOR(j, N) {
			cin >> dist[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));

	cout << find(0, 1);
	
	return 0;

}

