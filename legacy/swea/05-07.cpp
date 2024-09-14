#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
int Map[11][11];
int visited[11][11];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int MS;
struct Node{
    int y;
    int x;
    int dist;
    struct Node* next;
};
struct Queue{
    Node *front;
    Node *rear;
    int count;
};
void initQ(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
}
bool empty(Queue *queue){
    return queue->count == 0;
}
void push(Queue *queue, int x, int y, int dist){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->dist = dist;
    newNode->y = y; newNode->x = x;
    newNode->next = NULL;

    if(empty(queue)){
        queue->front = newNode;
    }else{
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
}
Node pop(Queue *queue){
    Node ret;
    Node *ptr;
    
    ptr = queue->front;
    ret.dist = ptr->dist;
    ret.x = ptr->x; ret.y = ptr->y;
    ret.next = NULL;
    queue->front = ptr->next;
    queue->count--;

    return ret;
}

void bfs_init(int map_size, int map[10][10]) {
    MS = map_size;
    for(int i=1;i<=MS;i++){
        for(int j=1;j<=MS;j++){
            visited[i][j] = 0;
            Map[i][j] = map[i-1][j-1];
        }
    }

}

int bfs(int x1, int y1, int x2, int y2) {
    for(int i=1;i<=MS;i++){
        for(int j=1;j<=MS;j++){
            visited[i][j] = 0;
        }
    }
    Queue Q;
    initQ(&Q);
    push(&Q,x1,y1,0);
    visited[y1][x1] = 1;

    while(!empty(&Q)){
        Node curr = pop(&Q);
        if(curr.x==x2&&curr.y==y2){
            return curr.dist;
        }
        for(int i=0;i<4;i++){
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            int dist = curr.dist+1;
            if(ny<1||ny>MS||nx<1||nx>MS||visited[ny][nx]||Map[ny][nx]==1) continue;
            visited[ny][nx] = 1;
            push(&Q,nx,ny,dist);
        }
    }

    return -1;
}

static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) score = 0;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);

	printf("#total score : %d\n", test_bfs());

	return 0;
}