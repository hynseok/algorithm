#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>


//////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define INF 100000001
const int MAX_ARR_SIZE = 200000;
const int H = (int)ceil(log2(MAX_ARR_SIZE));
const int Size = 1<<(H+1);

struct Node{
    int maxVal;
    int minVal;
    int alive;
    Node(): maxVal(-INF), minVal(INF), alive(0) {}
    Node(int Max, int Min, int Alive): maxVal(Max), minVal(Min), alive(Alive){}
};

int nodeN;
Node Tree[Size];
void initTree(){
    for(int i=0;i<Size;i++){
        Tree[i] = Node();
    }
    return;
}

Node mergeNode(const Node u, const Node v){
    int maxVal = max(u.maxVal,v.maxVal);
    int minVal = min(u.minVal,v.minVal);
    int alive = u.alive + v.alive;
    return Node(maxVal,minVal,alive);
}

void update(int node, int start, int end, int idx, int val){
    if(idx<start||end<idx) return;
    if(start==end){
        if(val == INF){
            Tree[node] = Node();
        }
        else{
            Tree[node] = Node(val,val,1);
        }
        return;
    }
    int mid = (start+end) / 2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    Tree[node] = mergeNode(Tree[node*2], Tree[node*2+1]);
    return;
}

Node Query(int node, int start, int end, int idx1, int idx2){
    if(idx2<start||end<idx1){
        return Node();
    }
    if(idx1<=start&&end<=idx2){
        return Tree[node];
    }
    int mid = (start + end) / 2;
    Node p = Query(node*2, start, mid, idx1, idx2);
    Node q = Query(node*2+1, mid+1, end, idx1, idx2);
    return mergeNode(p,q);
}

int findK(int node, int start, int end, int k){
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(Tree[node*2].alive<k){
        return findK(node*2+1, mid+1, end, k-Tree[node*2].alive);
    } 
    return findK(node*2, start, mid, k);
}

void init(int N, int mValue[]){
    initTree();
    nodeN = 0;
    for(int i=0;i<N;i++){
        update(1, 1, MAX_ARR_SIZE, ++nodeN, mValue[i]);
    }
    return;
}

void add(int M, int mValue[]){
    for(int i=0;i<M;i++){
        update(1,1,MAX_ARR_SIZE,++nodeN,mValue[i]);
    }
    return;
}

void erase(int mFrom, int mTo){
    for(int x = mTo; x>=mFrom; x--){
        int deleteIdx = findK(1,1,MAX_ARR_SIZE,x);
        update(1,1,MAX_ARR_SIZE,deleteIdx,INF);
    }
}

int find(int K){
    int totalAlive = Tree[1].alive;
    int virtualStart = totalAlive - K + 1;
    int realStart = findK(1,1,MAX_ARR_SIZE,virtualStart);
    Node ret = Query(1,1,MAX_ARR_SIZE,realStart,MAX_ARR_SIZE);
    return ret.maxVal - ret.minVal;
}


//////////////////////////////////


#define CMD_INIT (100)
#define CMD_ADD  (200)
#define CMD_ERASE  (300)
#define CMD_FIND (400)

static int arr[MAX_ARR_SIZE];
static int N, M;
static int from, to;

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ret, ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
            init(N, arr);
            ok = true;
        }
        else if (query == CMD_ADD)
        {
            scanf("%d", &M);
            for (int i = 0; i < M; i++)
                scanf("%d", &arr[i]);
            add(M, arr);
        }
        else if (query == CMD_ERASE)
        {
            scanf("%d%d", &from, &to);
            erase(from, to);

        }
        else if (query == CMD_FIND)
        {
            int K;
            scanf("%d", &K);
            ret = find(K);
            scanf("%d", &ans);

            if (ans != ret)
                ok = false;
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    //    freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}