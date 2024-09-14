#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
#define MAX_NODE 10000
enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
    return;
}

void addNode2Head(int data) 
{
    Node* temp = getNode(data);
    temp->next = head->next;
    head->next = temp;
    return;
}

void addNode2Tail(int data) 
{
    Node* temp = getNode(data);
    Node* prev_ptr = head;
    while(prev_ptr->next!=nullptr)
    {
        prev_ptr = prev_ptr->next;
    }
    prev_ptr->next = temp;
    return;
}

void addNode2Num(int data, int num) 
{
    Node* temp = getNode(data);
    Node* prev_ptr = head;
    for(int i=1;i<num;i++)
    {
        prev_ptr = prev_ptr->next;
    }
    temp->next = prev_ptr->next;
    prev_ptr->next = temp;
    return;
}

void removeNode(int data) 
{
    Node* prev_ptr = head;
    while(prev_ptr->next!=nullptr&&prev_ptr->next->data!=data){
        prev_ptr = prev_ptr->next;
    }
    if(prev_ptr->next!=nullptr){
        prev_ptr->next = prev_ptr->next->next;
    }
    return;
    
}

int getList(int output[MAX_NODE]) 
{
    int cnt = 0;
    Node* ptr = head->next;
    while(ptr!=nullptr){
        output[cnt] = ptr->data;
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("sll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}