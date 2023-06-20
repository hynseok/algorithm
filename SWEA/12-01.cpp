#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

////////////////////////////

#include <stdio.h>

////////////////////////////


#include <bits/stdc++.h>
using namespace std;

vector<int> CityName;
vector<pair<int,int>> graph[1500];
vector<pair<int,int>> Rgraph[1500];
unordered_map<int,int> CityIdx;
int cityidx;


int init(int N, int sCity[], int eCity[], int mCost[]) {
	for(int i=0;i<1500;i++){
		graph[i].clear();
		Rgraph[i].clear();
	}
	CityName.clear();
	CityIdx.clear();
	cityidx = 0;
	for(int i=0;i<N;i++){
		auto item = CityIdx.find(sCity[i]);
		if(item==CityIdx.end()){
			CityName.push_back(sCity[i]);
			CityIdx[sCity[i]] = cityidx;
			cityidx++;
		}
		item = CityIdx.find(eCity[i]);
		if(item==CityIdx.end()){
			CityName.push_back(eCity[i]);
			CityIdx[eCity[i]] = cityidx;
			cityidx++;
		}

		graph[CityIdx[sCity[i]]].push_back({CityIdx[eCity[i]],mCost[i]});
		Rgraph[CityIdx[eCity[i]]].push_back({CityIdx[sCity[i]],mCost[i]});
	}
	return cityidx;
}

void add(int sCity, int eCity, int mCost) {

	graph[CityIdx[sCity]].push_back({CityIdx[eCity],mCost});
	Rgraph[CityIdx[eCity]].push_back({CityIdx[sCity],mCost});

	return;
}

int cost(int mHub) {
	int d[1500];
	int Rd[1500];
	fill(d,d+1500,1000000000);
	fill(Rd,Rd+1500,1000000000);
	priority_queue<pair<int,int>> pq;
	pq.push({0,CityIdx[mHub]});
	d[CityIdx[mHub]] = 0;
	while(!pq.empty()){
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if(d[now]<dist) continue;

		for(int i=0;i<graph[now].size();i++){
			int cost = dist + graph[now][i].second;

			if(cost<d[graph[now][i].first]){
				d[graph[now][i].first] = cost;
				pq.push({-cost,graph[now][i].first});
			}
		}
	}
	
	pq.push({0,CityIdx[mHub]});
	Rd[CityIdx[mHub]] = 0;

	while(!pq.empty()){
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if(Rd[now]<dist) continue;

		for(int i=0;i<Rgraph[now].size();i++){
			int cost = dist + Rgraph[now][i].second;

			if(cost<Rd[Rgraph[now][i].first]){
				Rd[Rgraph[now][i].first] = cost;
				pq.push({-cost,Rgraph[now][i].first});
			}
		}
	}
	
	int ret = 0;
	for(int i=0;i<cityidx;i++){
		ret+=d[CityIdx[CityName[i]]];
		ret+=Rd[CityIdx[CityName[i]]];
	}

	return ret;
}



/////////////////////////////////////////////////////////////////////////

#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n;
	int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
	int sCity, eCity, mCost, mHub;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				okay = true;
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
				}
				scanf("%d", &ans);
				ret = init(n, sCityArr, eCityArr, mCostArr);
				cout<<ret;
				if (ans != ret)
					okay = false;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &sCity, &eCity, &mCost);
				add(sCity, eCity, mCost);
				break;
			case CMD_COST:
				scanf("%d %d", &mHub, &ans);
				ret = cost(mHub);
				cout<<ret;
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}