#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
#define MAX_NODE 10000
enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
    return;
}

void addNode2Head(int data) 
{
    Node* node = getNode(data);
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->prev = head;
    
    return;
}

void addNode2Tail(int data) 
{
    Node* node = getNode(data);
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
    node->next = tail; 

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
    prev_ptr->next->prev = temp;
    prev_ptr->next = temp;
    temp->prev = prev_ptr;
    return;
}

int findNode(int data) 
{
    Node* node = head;
    int cnt = 0;
    while(node->next!=nullptr&&node->data!=data){
        node = node->next;
        cnt++;
    }

    return cnt;
}

void removeNode(int data) 
{
    Node* node = head;
    while(node->next!=nullptr&&node->data!=data){
        node = node->next;
    }
    if(node->next!=nullptr){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    return;
}

int getList(int output[MAX_NODE]) 
{
    int cnt = 0;
    Node* ptr = head->next;
    while(ptr->next!=nullptr){
        output[cnt] = ptr->data;
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

int getReversedList(int output[MAX_NODE]) 
{
    int cnt = 0;
    Node* ptr = tail->prev;
    while(ptr->prev!=nullptr){
        output[cnt] = ptr->data;
        cnt++;
        ptr = ptr->prev;
    }
    return cnt;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
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
	//freopen("dll_input.txt", "r", stdin);

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