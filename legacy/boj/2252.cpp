#include <bits/stdc++.h>
#define FOR(i, N) for(int i=0; i<N; i++)
#define FOR1(i, N) for(int i=1; i<=N; i++)
#define MAX_NODE 32001
using namespace std;


int N, M;
vector<short> node[MAX_NODE];
short degree[MAX_NODE];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	int s, e;
	queue<short> Q;

	FOR(i, M) {
		cin >> s >> e;
		node[s].push_back(e);
		degree[e]++;
	}

	FOR1(i, N) {
		if(degree[i] == 0)
			Q.push(i);
	}

	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		cout << cur << " ";
		for(int i=0; i<node[cur].size(); i++) {
			int next = node[cur][i];
			degree[next]--;

			if(degree[next] == 0) Q.push(next);
		}
	}

	return 0;
}
