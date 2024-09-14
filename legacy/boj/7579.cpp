#include <bits/stdc++.h>
#define MAX_APP 101
#define MAX_COST 10001
using namespace std;

int N, M;
int m[MAX_APP];
int c[MAX_APP];
int dp[MAX_APP][MAX_COST] = {0,};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int ans = MAX_COST;
	
	cin >> N >> M;

	for(int i=1;i<=N;i++) {
		cin >> m[i];
	}
	for(int i=1;i<=N;i++) {
		cin >> c[i];
	}
	
	for(int i=1;i<=N;i++) {
		for(int j=0;j<=MAX_COST;j++){
			if(j >= c[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]]+m[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}

	for(int i=1;i<=N;i++) {
		for(int j=0;j<=MAX_COST;j++){
			if(dp[i][j] >= M)
				ans = min(ans, j);
		}
	}

	cout << ans;
}

