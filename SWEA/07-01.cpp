#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			printf("%d ",result[j]);
		scanf("%d", &check);
		if (check != sum)
			score = 0;
        printf("\n");
	}
	return score;
}

int main(void) {
	setbuf(stdout, NULL);
	//freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}

struct Node{
    int id;
    int income;
};

struct heap{
    Node arr[100001];
    int size;
};

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

heap hp;

void init()
{
    hp.size = 0;    
}

void heapify(int curr, int size){
    int left = curr * 2 + 1;
    int right = curr * 2 + 2;
    int max = curr;
    if(left<size&&hp.arr[left].income>hp.arr[max].income) max = left;
    if(right<size&&hp.arr[right].income>hp.arr[max].income) max = right;

    if(max!=curr){
        swap(&hp.arr[curr],&hp.arr[max]);
        heapify(max,size);
    }
}

void addUser(int uID, int income) 
{
    int curr = ++hp.size;
    hp.arr[curr].id = uID;
    hp.arr[curr].income = income;
    if(hp.size<10){
        for(int size = hp.size;size>0;size--){
            heapify(size,hp.size);
        }
    }
    else{
        for(int size = 10;size>0;size--){
            heapify(size,10);
        }
    }
}

int getTop10(int result[10]) 
{
    int flag = 0;
    for(int i=0;i<hp.size;i++){
        result[i] = hp.arr[i].id;
        if(i==9){
            flag = 1;
            break;
        }
    }
    if(flag==1) return 10;
    return hp.size;
}

// https://gmlwjd9405.github.io/2018/05/10/algorithm-heap-sort.html