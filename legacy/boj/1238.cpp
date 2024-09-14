#include <bits/stdc++.h>
using namespace std;

#define INT_32_MAX 2147483647
typedef pair<int,int> pii;
typedef vector<pair<int,int> > pairlist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	pairlist adj_matrix[1001];
	int dist[1001][1001];
	int N, M, X;
	int start, end, d;
	int ans = 0;

	for(int i=0;i<1001;i++) {
		for(int j=0;j<1001;j++) { 
			dist[i][j] = INT_32_MAX;
		}
	}
	
	cin >> N >> M >> X;
	for(int i=0; i<M; i++) {
		cin >> start >> end >> d;
		adj_matrix[start].push_back(make_pair(end, d));	
	}	

	for(int d=1; d<N+1; d++) {
		priority_queue<pii> pq;
		pq.push(make_pair(0, d));
		dist[d][d] = 0;
		while(!pq.empty()){
			int now_dist = -pq.top().first;
			int now = pq.top().second;
			pq.pop();

			if(dist[d][now]<now_dist)
				continue;

			for(int i=0; i<adj_matrix[now].size(); i++) {
				int cost = now_dist + adj_matrix[now][i].second;

				if(cost < dist[d][adj_matrix[now][i].first]) {
					dist[d][adj_matrix[now][i].first] = cost;
					pq.push(make_pair(-cost, adj_matrix[now][i].first));
				}
			}
		}
	}

	for(int i=1;i<N+1;i++) {
		int sum = dist[i][X] + dist[X][i];
		if(ans < sum)
			ans = sum;
	}
	
	cout << ans;	

}
