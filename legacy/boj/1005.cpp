#include <bits/stdc++.h>
#define FOR(i,M,N) for(int i=M; i<N; i++)

using namespace std;

int TC;
int N, K;
int degree[1001];
int weight[1001];
int dp[1001];
vector<int> edge[1001];

int main() {
	cin >> TC;

	int start, end;
	while(TC--){
		memset(degree, 0, sizeof(degree));
		memset(dp, 0, sizeof(dp));
		
		int target;
		queue<int> Q;

		cin >> N >> K;
		FOR(i,1,N+1)
		{
			cin >> weight[i];
			dp[i] = weight[i];
		}
		FOR(i,0,K) {
			cin >> start >> end;
			edge[start].push_back(end);
			degree[end]++;
		}
		
		cin >> target;
		
		FOR(i,1,N+1) {
			if(i==target)continue;
			if(degree[i] == 0){
				Q.push(i);
			}
		}

		while(!Q.empty()) {
			int curr;
			curr = Q.front();
			Q.pop();
			

			FOR(i,0,edge[curr].size()){
				int next = edge[curr][i];
				degree[next]-- ;
				dp[next] = max(dp[next], dp[curr] + weight[next]);

				if(degree[next] == 0) {
					Q.push(next);
				}
			}
		}
		cout << dp[target] << "\n";
	}
	return 0;

}

