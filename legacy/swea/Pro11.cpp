#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_MIN_TRAVEL_TIME 3
#define CMD_MIN_PRICE 4

/////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define MAXNODE 61
#define TIME 24
#define INF 987654321

typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> pip;
int dist1[MAXNODE];
int dist2[MAXNODE][TIME];
vector<pii> adj1[MAXNODE];
vector<pii> adj2[MAXNODE][TIME];


void init(int N)
{

}

void add(int mStartAirport, int mEndAirport, int mStartTime, int mTravelTime, int mPrice)
{
	int isExist = 0;
	for(auto &[dest, cost]:adj1[mStartAirport]){
		if(dest == mEndAirport){
			isExist = 1;
			if(mPrice < cost){
				cost = mPrice;
			}
			break;
		}
	}
	if(!isExist){
		adj1[mStartAirport].emplace_back(mEndAirport,mPrice);
	}

	isExist = 0;
	for(auto &[dest, time] : adj2[mStartAirport][mStartTime]){
		if(dest == mEndAirport){
			isExist = 1;
			if(mTravelTime < time){
				time = mTravelTime;
			}
			break;
		}
	}
	if(!isExist){
		adj2[mStartAirport][mStartTime].emplace_back(mEndAirport,mTravelTime);
	}


}

int minTravelTime(int mStartAirport, int mEndAirport, int mStartTime)
{
	priority_queue<pip, vector<pip>, greater<>> PQ;
	for(int i=0;i<MAXNODE;i++){
		for(int j=0;j<TIME;j++){
			dist2[i][j] = INF;
		}
	}
	
	return -1;
}

int minPrice(int mStartAirport, int mEndAirport)
{
	priority_queue<pii, vector<pii>, greater<>> PQ;
	for(int i=0;i<MAXNODE;i++){
		dist1[i] = INF;
	}
	dist1[mStartAirport] = 0;
	PQ.emplace(0,mStartAirport);
	while(!PQ.empty()){
		auto [totalCost,curr] = PQ.top();
		PQ.pop();

		if(totalCost != dist1[curr]) continue;
		if(curr == mEndAirport) return totalCost;

		for(auto &[next, cost] : adj1[curr]){
			if(dist1[next] > dist1[curr] + cost){
				dist1[next] = dist1[curr] + cost;
				PQ.emplace(dist1[next], next);
			}
		}
	}

	return -1;
}
/////////////////////////////////////////////////////////////////////////

static bool run()
{
	int numQuery;
	int N, mStartAirport, mEndAirport, mStartTime, mTravelTime, mPrice;
	int userAns, ans;

	bool isCorrect = false;

	scanf("%d", &numQuery);

	for (int q = 0; q < numQuery; q++)
	{
		int cmd;
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);
			init(N);
			isCorrect = true;
			break;
		case CMD_ADD:
			scanf("%d %d %d %d %d", &mStartAirport, &mEndAirport, &mStartTime, &mTravelTime, &mPrice);
			add(mStartAirport, mEndAirport, mStartTime, mTravelTime, mPrice);
			break;
		case CMD_MIN_TRAVEL_TIME:
			scanf("%d %d %d", &mStartAirport, &mEndAirport, &mStartTime);
			userAns = minTravelTime(mStartAirport, mEndAirport, mStartTime);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				isCorrect = false;
			}
			break;
		case CMD_MIN_PRICE:
			scanf("%d %d", &mStartAirport, &mEndAirport);
			userAns = minPrice(mStartAirport, mEndAirport);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				isCorrect = false;
			}
			break;
		default:
			isCorrect = false;
			break;
		}
	}
	return isCorrect;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}