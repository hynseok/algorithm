#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 100
///////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100

struct POS{
    int y;
    int x;
};
struct CELL{
    int type;
    int energy;
    int version;
    POS pos;
};

struct compare{
    bool operator()(CELL* a, CELL* b){
        if(a->energy == b->energy){
            if(a->pos.y == b->pos.y){
                return a->pos.x > b->pos.x;
            }
            else{
                return a->pos.y > b->pos.y;
            }
        }
        else{
            return a->energy < b->energy;
        }
    }
};

CELL Map[101][101];
priority_queue<CELL*,vector<CELL*>,compare> pq;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int N;
int version;
int nCnt[3];

void bfs(int y, int x, int type){
    queue<pair<int,int>> Q;
    Q.push({y,x});
    while(!Q.empty()){
        pair<int,int> pos = Q.front();
        Q.pop();
        int cy = pos.first; 
        int cx = pos.second;

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<=0||nx<=0||ny>N||nx>N) continue;
            if(Map[ny][nx].version>=version) continue;
            if(Map[ny][nx].type == (3-type)) continue;

            Map[ny][nx].version = version;
            if(Map[ny][nx].type == type){
                Q.push({ny,nx});
            }
            else if(Map[ny][nx].type==0){
                pq.push(&Map[ny][nx]);
            }
        }
    }
}

void init(int N, int mDish[MAX_N][MAX_N])
{
    ::N = N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            Map[i][j].energy = mDish[i-1][j-1];
            Map[i][j].type = 0;
            Map[i][j].pos = {i,j};
            Map[i][j].version = 0;
        }
    }
    version = 0;
    nCnt[1] = nCnt[2] = 0;
}

int dropMedicine(int mTarget, int mRow, int mCol, int mEnergy)
{
    version++;
    int currType = Map[mRow][mCol].type;
    if(currType!=0&&currType!=mTarget) return nCnt[mTarget];

    CELL *cell = &Map[mRow][mCol];
    if(cell->type==0){
        cell->type = mTarget;
        nCnt[mTarget]++;
        mEnergy -= cell->energy;
    }
    cell->version = version;

    pq = {};
    while(mEnergy>0){
        bfs(cell->pos.y,cell->pos.x,mTarget);
        if(pq.size()==0)break;
        cell = pq.top();
        pq.pop();
        cell->type = mTarget;
        nCnt[mTarget]++;
        mEnergy -= cell->energy;
    }

    return nCnt[mTarget];
}

int cleanBacteria(int mRow, int mCol)
{
    version++;
    int type = Map[mRow][mCol].type;
    if(type==0) return -1;
    queue<pair<int,int>> Q;
    Q.push({mRow,mCol});

    while(!Q.empty()){
        pair<int,int> pos = Q.front();
        Q.pop();
        int cy = pos.first;
        int cx = pos.second;

        Map[cy][cx].type = 0;
        nCnt[type]--;

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<=0||nx<=0||ny>N||nx>N) continue;
            if(Map[ny][nx].version>=version) continue;
            if(Map[ny][nx].type != type) continue;

            Q.push({ny,nx});
            Map[ny][nx].version = version;
        }
    }

    return nCnt[type];
}
/////////////////////////////////////////
#define CMD_INIT 100
#define CMD_DROP 200
#define CMD_CLEAN 300

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ret, ans;
    bool ok = false;
    static int dish[MAX_N][MAX_N];

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            int N;
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    scanf("%d", &dish[i][j]);
                }
            }
            init(N, dish);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mTarget;
            int mRow, mCol;
            int mEnergy;
            scanf("%d %d %d %d", &mTarget, &mRow, &mCol, &mEnergy);
            ret = dropMedicine(mTarget, mRow, mCol, mEnergy);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_CLEAN)
        {
            int mRow, mCol;
            scanf("%d %d", &mRow, &mCol);
            ret = cleanBacteria(mRow, mCol);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
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