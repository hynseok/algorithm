#include <bits/stdc++.h>
#define CITYMAX 200
using namespace std;
typedef pair<int,pair<int,int>> pip;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cityPQ[CITYMAX];
priority_queue<pip,vector<pip>,greater<pip>> DispatchPQ;
priority_queue<pair<int,int>> PQ;
int pay[CITYMAX]; 
int collect[CITYMAX]; 
bool Visit[CITYMAX]; 
int CityN, OfficialN, WaitOfficial, TaxSum;

void init(int N, int M)
{
    CityN = N;
    OfficialN = M;
    WaitOfficial = M;
    TaxSum = 0;
    for(int i=1;i<CityN;i++){
        while(!cityPQ[i].empty()) cityPQ[i].pop();
        pay[i] = collect[i] = 0;
        Visit[i] = false;
    }
    while(!PQ.empty()) PQ.pop();
    while(!DispatchPQ.empty()) DispatchPQ.pop();
}

void taxToCity(int id, int t, int tax){
    cityPQ[id].push({t,tax});
}

int collectTax(int id, int t){
    int taxsum = 0;
    while(!cityPQ[id].empty()&&cityPQ[id].top().first<=t){
        taxsum +=cityPQ[id].top().second;
        cityPQ[id].pop();
    }
    return taxsum;
}

int PredictCity(){
    while(!PQ.empty()&&(Visit[-PQ.top().second]||PQ.top().first!=pay[-PQ.top().second]-collect[-PQ.top().second])) PQ.pop();
	if(PQ.empty()||PQ.top().first==0)return 0;
	return -PQ.top().second;
}

void Dispatch(int id){
	Visit[id] = true;
}

void Pcollect(int id, int tax){
	Visit[id] = false;
	collect[id] += tax;
	PQ.push({pay[id]-collect[id],-id});
}

void Pupdate(int id, int tax){
	pay[id] += tax;
	if(!Visit[id]){
		PQ.push({pay[id]-collect[id],-id});
	}
}

void Pupdate(int time, int id, int tax){
	DispatchPQ.push({time,{-id,-tax}});
}

void Flow(int time){
	while(!DispatchPQ.empty()&&DispatchPQ.top().first<=time){
		int t = DispatchPQ.top().first;
		int x = DispatchPQ.top().second.first, y = DispatchPQ.top().second.second;
		DispatchPQ.pop();

		if(y>=0){
			WaitOfficial += 1;
			TaxSum += y;
			Pcollect(x,y);
		}
		else if(x>=0){
			int tax = collectTax(x,t);
			DispatchPQ.push({t+x,{x,tax}});
		}
		else{
			Pupdate(-x,-y);
		}

		if(DispatchPQ.empty()||DispatchPQ.top().first>t){
			while(WaitOfficial>0&&PredictCity()>0){
				int id = PredictCity();
				Dispatch(id);
				DispatchPQ.push({t+id,{id,-1}});
				WaitOfficial -= 1;
			}
		}
	}
}

void destroy(){}

int check(int tStamp)
{
    Flow(tStamp);
	return TaxSum;
}

int order(int tStamp, int mCityA, int mCityB, int mTax) //수도의 곡물의 양  반ㅏ
{
	Flow(tStamp-1);
	taxToCity(mCityB,tStamp+abs(mCityA-mCityB),mTax);
	Pupdate(tStamp+max(0,abs(mCityA-mCityB)-mCityB),mCityB,mTax);
    return check(tStamp);
}

/////////////////////////////////////////////////
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_ORDER 300
#define CMD_CHECK 400



static int run()
{
	int C;
	int isOK = 0;
	int cmd, ret, chk;

	int mN, mM;
	int mTStamp;

	int mCityA, mCityB, mTax;

	scanf("%d", &C);

	for (int c = 0; c < C; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d %d ", &mN, &mM);
			init(mN, mM);
			isOK = 1;
			break;

		case CMD_ORDER:			
			scanf("%d %d %d %d", &mTStamp, &mCityA, &mCityB, &mTax);
			ret = order(mTStamp, mCityA, mCityB, mTax);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		case CMD_CHECK:
			scanf("%d", &mTStamp);
			ret = check(mTStamp);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}
	destroy();
	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}