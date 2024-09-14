#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

int childList[100][6];
int childCnt[100];
int king[100] = {0, };
int visited[100] = {0, };
int kingN, ret;
void dfs_init(int N, int path[100][2]){
    for(int i=0;i<100;i++){
        childCnt[i] = 0;
        for(int j=0;j<6;j++) childList[i][j] = 0;
    }
    int parent, child;
    for(int i=0;i<N;i++){
        parent = path[i][0];
        child = path[i][1];
        childList[parent][childCnt[parent]] = child;
        childCnt[parent]++;
    }

}

void DFS(int start){
    if(king[kingN-1]<start){
        king[kingN] = start;
        kingN++;
    }
    visited[start] = 1;
    for(int i=0;i<childCnt[start];i++){
        int next = childList[start][i];
        if(visited[next]||next==0)continue;
        DFS(next);
    }
    return;
}

int dfs(int n)
{
    king[0] = n;
    kingN = 1;
    for(int i=1;i<100;i++){
        visited[i] = 0;
        king[i] = 0;
    }
    DFS(n);

    if(king[1]!=0) return king[1];
	return -1;
}

static int p[MAX_K+2];
static int c[MAX_K+2];
static int path[MAX_N][2];
static void makeTree(int n) {
	for (int i = 1; i < MAX_K+2; ++i) {
		p[i] = c[i] = -1;
	}
	c[pseudo_rand(MAX_K + 1) + 1] = 0;
	for (int i = 0; i < n; ++i) {
		int pi = pseudo_rand(MAX_K + 1) + 1;
		while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
			++pi;
			if (pi == MAX_K + 2)
				pi = 1;
		}
		int ci = pseudo_rand(MAX_K + 1) + 1;
		while (c[ci] >= 0) {
			++ci;
			if (ci == MAX_K + 2)
				ci = 1;
		}
		p[ci] = pi;
		++c[pi];
		c[ci] = 0;
	}
	bool check[MAX_K + 2] = { false };
	for (int i = 0; i < n; ++i) {
		int e = pseudo_rand(MAX_K + 1) + 1;
		while (check[e] || c[e] < 0 || p[e] == -1) {
			++e;
			if (e == MAX_K + 2)
				e = 1;
		}
		check[e] = true;
		path[i][0] = p[e];
		path[i][1] = e;
	}
}

int main() {
	setbuf(stdout, NULL);
	int T;
	//freopen("dfs_input.txt", "r", stdin);
	scanf("%d", &T);

	int totalScore = 0;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;

		scanf("%d %d %d", &n, &q, &seed);

		makeTree(n - 1);
		dfs_init(n, path);

		bool check[MAX_K + 2] = { false };
		int score = 100;
		for (int i = 0; i < q; ++i) {
			int k, ret, correct;

			scanf("%d", &k);

			ret = dfs(k);
            printf("%d\n",ret);
			scanf("%d", &correct);

			if (ret != correct)
				score = 0;
		}
		printf("#%d : %d\n", tc, score);
		totalScore += score;
	}
	printf("#total score : %d\n", totalScore / T);

	return 0;
}