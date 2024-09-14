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

heap hp;
Node tempN[100001];

void init()
{
    for(int i=0;i<100001;i++){
        hp.arr[i].id = -1;
        hp.arr[i].income = -1;
        tempN[i].id = -1;
        tempN[i].income = -1;
    }
    hp.size = 0;    
}


void addUser(int uID, int income) 
{
    int curr = ++hp.size;
    while((curr!=1)&&(income>=hp.arr[curr/2].income)){
        if(income==hp.arr[curr/2].income){
            if(uID<hp.arr[curr/2].id){
                hp.arr[curr] = hp.arr[curr/2];
                curr/=2;
                break;
            }
            break;
        }
        hp.arr[curr] = hp.arr[curr/2];
        curr/=2;
    }
    hp.arr[curr].id = uID;
    hp.arr[curr].income = income;
    
}

Node getTop(){
    int parent, child;
    Node temp, ret;
    
    ret = hp.arr[1];
    temp = hp.arr[hp.size--];
    parent = 1;
    child = 2;
    
    while(child <= hp.size){
        if(child<hp.size&&hp.arr[child].income<hp.arr[child+1].income){
            child++;
        }
        if(child<hp.size&&hp.arr[child].income==hp.arr[child+1].income){
            if(hp.arr[child].id>hp.arr[child+1].id) child++;
        }
        if(temp.income>=hp.arr[child].income) break;
        hp.arr[parent] = hp.arr[child];
        parent = child;
        child*=2;
    }
    hp.arr[parent] = temp;
    return ret;
}

int getTop10(int result[10]) 
{   
    if(hp.size<=10){
        int hsize = hp.size;
        for(int i=0;i<hsize;i++){
            tempN[i] = getTop();
            result[i] = tempN[i].id;
        }
        for(int i=0;i<hsize;i++){
            addUser(tempN[i].id,tempN[i].income);
        }
        return hsize;
    }
    for(int i=0;i<10;i++){
        tempN[i] = getTop();
        result[i] = tempN[i].id;
    }
    for(int i=0;i<10;i++){
        addUser(tempN[i].id,tempN[i].income);
    }
    return 10;
}
