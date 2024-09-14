#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2048
#define MAXID 50001
#define NN 128
#define INF 1000000000
#define INFPIP{INF,{INF,INF}}

struct Result {
	int id;
	int num;
};
typedef pair<int,pair<int,int>> pip;

priority_queue<pip,vector<pip>,greater<pip>> leaf[NN+1];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
queue<pair<int,int>> Q;
pip Tree[NN*2];
int seat[MAXN][11][11];
int reserved[MAXN][11][11];
pip reserve_info[MAXID];
int visited[11][11];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int N, visitN;

int posTonum(pair<int,int> pos){
    return (pos.first-1)*10 + pos.second;
}

pip find(int node, int start, int end, int x, int y){
    int mid = (start + end) / 2;
    if(x<=start&&end<=y)return Tree[node];
    if(end<x||y<start) return INFPIP;
    return min(find(node*2, start, mid, x, y), find(node*2+1, mid+1, end, x, y));
}

void update(int node){
    Tree[node] = min(Tree[node*2], Tree[node*2+1]);
    if(node>1) update(node/2);
}

void updateLeaf(int mSeat){
    pip val = Tree[NN+mSeat-1];
    Tree[NN+mSeat-1] = INFPIP;
    while(!leaf[mSeat].empty()){
        pip curr = leaf[mSeat].top();
        if(seat[curr.first][curr.second.first][curr.second.second]==mSeat){
            Tree[NN+mSeat-1] = curr;
            break;
        }
        leaf[mSeat].pop();
    }
    if(val!=Tree[NN+mSeat-1])update((NN+mSeat-1)/2);
}

void addCluster(pip cluster, int mSeat){
    seat[cluster.first][cluster.second.first][cluster.second.second] = mSeat;
    leaf[mSeat].push(cluster);
    updateLeaf(mSeat);
}

void removeCluster(pip cluster){
    int mSeat = seat[cluster.first][cluster.second.first][cluster.second.second];
    seat[cluster.first][cluster.second.first][cluster.second.second] = 0;
    updateLeaf(mSeat);
}

void init(int N)
{
    ::N = N;
    for(int i=1;i<=NN;i++){
        while(!leaf[i].empty())leaf[i].pop();
    }
    for(int i=1;i<NN*2;i++){
        Tree[i] = INFPIP;
    }
    for(int i=1;i<=N;i++){
        for(int y=1;y<=10;y++){
            for(int x=1;x<=10;x++){
                reserved[i][y][x] = seat[i][y][x] = 0;
            }
        }
        addCluster({i,{1,1}},100);
    }
}

Result reserveSeats(int mID, int K)
{
	pip res = find(1,1,NN,K,NN);
	if(res.first>N)return {0,0}; 
	reserve_info[mID] = res;
	removeCluster(res);

    visitN +=1;
    PQ.push(res.second);
    for(int i=1;i<=K;i++){
        pair<int,int> curr = PQ.top();
        PQ.pop();
        reserved[res.first][curr.first][curr.second] = mID;
        for(int j=0;j<4;j++){
            int ny = curr.first + dy[j];
            int nx = curr.second + dx[j];
            if(1<=nx&&1<=ny&&10>=nx&&10>=ny){
                if(reserved[res.first][ny][nx]==0&&visited[ny][nx]!= visitN){
                    visited[ny][nx] = visitN;
                    PQ.push({ny,nx});
                }
            }
        }
    }
    visitN+=1;
    while(!PQ.empty()){
        pair<int,int> curr = PQ.top();
        PQ.pop();
        if(visited[curr.first][curr.second]!=visitN){
            pair<int,int> minSeat = {INF,INF};
            int cnt = 0;
            visited[curr.first][curr.second] = visitN;
            Q.push(curr);
            while(!Q.empty()){
                pair<int,int> qcurr = Q.front();
                Q.pop();
                minSeat = min(minSeat,qcurr);
                cnt+=1;

                for(int i=0;i<4;i++){
                    int ny = qcurr.first + dy[i];
                    int nx = qcurr.second + dx[i];
                    if(1<=ny&&1<=nx&&10>=ny&&10>=nx){
                        if(visited[ny][nx]!=visitN&&reserved[res.first][ny][nx]==0){
                            visited[ny][nx] = visitN;
                            Q.push({ny,nx});
                        }
                    }
                }
            }
            addCluster({res.first,minSeat},cnt);
        }
    }
    return {res.first,posTonum(res.second)};
}

Result cancelReservation(int mID)
{
	removeCluster(reserve_info[mID]);

    int mTheater = reserve_info[mID].first;
    pair<int,int> start = reserve_info[mID].second;
    pair<int,int> minSeat = {INF,INF};
    int cnt = 0, sumSeat = posTonum(start);
    visited[start.first][start.second] = ++visitN;
    reserved[mTheater][start.first][start.second] = 0;
    Q.push(start);

    while(!Q.empty()){
        pair<int,int> curr = Q.front();
        Q.pop();
        minSeat = min(minSeat,curr);
        cnt+=1;

        for(int i=0;i<4;i++){
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if(1<=ny&&1<=nx&&10>=ny&&10>=nx&&visited[ny][nx]!=visitN){
                visited[ny][nx] = visitN;
                if(reserved[mTheater][ny][nx] == mID){
                sumSeat += posTonum({ny,nx});
                reserved[mTheater][ny][nx] = 0;
                Q.push({ny,nx});
                }
                else if(reserved[mTheater][ny][nx]==0){
                    if(seat[mTheater][ny][nx]>0){
                    removeCluster({mTheater,{ny,nx}});
                    }
                    Q.push({ny,nx});
                }
            }
        }
    }
    addCluster({mTheater,minSeat},cnt);
    return {mTheater,sumSeat};
}

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT	0
#define CMD_RESERVE	1
#define CMD_CANCEL	2

static bool run()
{
	int q;
	scanf("%d", &q);

	int cmd, param1, param2;
	int ans1, ans2;
	bool okay = false;
	Result res;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INIT:
			scanf("%d", &param1);
			init(param1);
			okay = true;
			break;

		case CMD_RESERVE:
			scanf("%d %d", &param1, &param2);
			res = reserveSeats(param1, param2);
			scanf("%d %d", &ans1, &ans2);
			if (res.id != ans1 || res.num != ans2)
				okay = false;
			break;

		case CMD_CANCEL:
			scanf("%d", &param1);
			res = cancelReservation(param1);
			scanf("%d %d", &ans1, &ans2);
			if (res.id != ans1 || res.num != ans2)
				okay = false;
			break;

		default:
			okay = false;
			break;
		}
	}
	return okay;
}

int main()
{
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