#include <bits/stdc++.h>
#define FOR(I, N) for(int I=0;I<N;I++)
#define MAX_NODE 10001
#define MAX_EDGE 100001
using namespace std;

typedef struct edge {
	int origin;
	int dest;
	int weight;
} edge;

edge _edge[MAX_EDGE];
int parent[MAX_NODE];
int _rank[MAX_NODE];

bool compare(edge a, edge b) { return a.weight < b.weight; }

void make_set(int x) {
	parent[x] = x;
	_rank[x] = 0;
}

int find_set(int x) {
	if (x != parent[x])
		parent[x] = find_set(parent[x]);

	return parent[x];
}

void link_(int x, int y) {
	if(_rank[x] > _rank[y])
		parent[y] = x;
	else
	{
		parent[x] = y;
		if(_rank[x] == _rank[y])
			_rank[y]++;
	}
}

void union_(int x, int y) {
	x = find_set(x);
	y = find_set(y);

	if(x == y)
		return;
	link_(x, y);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int V, E;
	int u, v;
	int weight_sum = 0;

	cin >> V >> E;

	FOR(i, E)
		cin >> _edge[i].origin >> _edge[i].dest >> _edge[i].weight;

	sort(_edge, _edge+E, compare);

	for(int i=1; i<=V; i++) {
		make_set(i);
	}

	FOR(i, E) {
		u = _edge[i].origin;
		v = _edge[i].dest;
		if(find_set(u) != find_set(v)) {
			weight_sum += _edge[i].weight;
			union_(u, v);
		}
	}

	cout << weight_sum;

}