#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
/////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
map <int,set<int>> Map;

typedef struct listnode{
    int data;
    struct listnode* next;
}Node;

Node node[200000];
int nodeCnt;
Node* head[17576];
Node* tail[17576];
int stringN;
string PrimeS;

int hashF(string s){
    
    int ret = 0;
    for(int i=0;i<s.size();i++){
        ret*=26;
        ret+=s[i]-'a';
    }
    return ret;
}

Node* getNode(int data){
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void clear(){
    nodeCnt = 0;
    for(int i=0;i<17576;i++){
        head[i] = nullptr;
		tail[i] = head[i];
    }
}

void insertback(int idx, int data){
	Node* newNode = getNode(data);
	if(head[idx]==nullptr){
        head[idx] = newNode;
		tail[idx] = head[idx];
        return;
    }
	else{
		tail[idx]->next = newNode;
		tail[idx] = tail[idx]->next;
	}
}

void insert(int idx, int data){
    Node* newNode = getNode(data);
    if(head[idx]==nullptr){
        head[idx] = newNode;
        return;
    }
    if(data<head[idx]->data){
        newNode->next = head[idx];
        head[idx] = newNode;
        return;
    }
    Node* curr = head[idx];
    while(curr->next!=nullptr&&curr->next->data<data){
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void deleteNode(int idx, int data){
    if(head[idx]==nullptr) return;
    if(head[idx]->data == data){
        head[idx] = head[idx]->next;
        return;
    }
    Node* curr = head[idx];
    while(curr->next!=nullptr&&curr->next->data!=data){
        curr = curr->next;
    }
    if(curr->next==nullptr)return;
    curr->next = curr->next->next;
}

void init(int n, char init_string[]){
    PrimeS = (string)init_string;
	stringN = PrimeS.size();

    clear();
    for(int i=0;i<stringN-2;i++){
        char S[4]; S[0] = PrimeS[i]; S[1] = PrimeS[i+1]; S[2] = PrimeS[i+2]; S[3] = '\0';
        int hash = hashF(S);
        insertback(hash,i);
    }
}

int change(char string_A[], char string_B[]){
    int Ahash = hashF(string_A);
    int ret = 0;
    int idx;
    Node* ptr = head[Ahash];
    while(ptr!=nullptr){
        ret++;
        idx = ptr->data;
        for(int i=idx-2;i<=idx+2;i++){
			if(i<0)continue;
            if(i>=stringN-2)break;
			char S[4]; S[0] = PrimeS[i]; S[1] = PrimeS[i+1]; S[2] = PrimeS[i+2]; S[3] = '\0';
            int hashN = hashF(S);
            deleteNode(hashN,i);
		}
        for(int i=idx;i<idx+3;i++){
            PrimeS[i] = string_B[i-idx];
        }
        for(int i=idx-2;i<=idx+2;i++){
			if(i<0)continue;
            if(i>=stringN-2)break;
			char S[4]; S[0] = PrimeS[i]; S[1] = PrimeS[i+1]; S[2] = PrimeS[i+2]; S[3] = '\0';
            int hash = hashF(S);
            insert(hash,i);
		}
        
        while(ptr!=nullptr){
            if((ptr->data)>idx+2) break;
            ptr = ptr->next;
        }
    }
    
    
	return ret;
}

void result(char ret[]){
	for(int i=0;i<stringN;i++){
		ret[i] = PrimeS[i];
	}
}

/////////////////////////////////////////////////////
static int seed = 5;  // seed can be changed
static int pseudo_rand(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

#define MAXL (50005)
#define DUMMY_LEN (5959)

static int init_string_len = 0, char_type = 0, query_cnt = 0;
static char dummy1[DUMMY_LEN];
static char init_string[MAXL];
static char dummy2[DUMMY_LEN];
static char result_string[MAXL];
static char dummy3[DUMMY_LEN];
static char user_ans_string[MAXL];
static char dummy4[DUMMY_LEN];
static char string_A[4], string_B[4];


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
	setbuf(stdout, NULL);
//	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int total_score = 0;
	for (int TC = 1; TC <= T; TC++) {
		int score = 100;
		scanf("%d%d%d%d", &seed, &init_string_len, &char_type, &query_cnt);
		
		for (int i = 0; i < init_string_len; i++)
		{
			init_string[i] = pseudo_rand() % char_type + 'a';
		}
		init_string[init_string_len] = '\0';

		init(init_string_len, init_string);

		string_A[3] = string_B[3] = '\0';
		for (int i = 0; i < query_cnt; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				string_A[k] = pseudo_rand() % char_type + 'a';
				string_B[k] = pseudo_rand() % char_type + 'a';
			}
			int user_ans = change(string_A, string_B);
			int ans;
			scanf("%d", &ans);

			if (ans != user_ans)
			{
				score = 0;
            }
		}

		result(user_ans_string);
		scanf("%s", result_string);

		
		for (int i = 0; i < init_string_len; i++)
		{
			if (result_string[i] != user_ans_string[i])
			{
				score = 0;
				break;
			}
		}

		total_score += score;
		printf("#%d %d\n", TC, score);
	}
	printf("Total score : %d\n", total_score/T);

	return 0;
}