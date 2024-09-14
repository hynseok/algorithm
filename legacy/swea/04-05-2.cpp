#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define MAX_NODE 50001
///////////////////////////////////////////////////////
int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}
///////////////////////////////////////////////////////////////
int nameToint(const char *src){
	int ret = 0;
	int len = mstrlen(src);
	int i = 0;
	for(;i<len;i++) ret = (ret<<5) | (src[i] - 'a' + 1);
	for(;i<6;i++) ret = (ret<<5);
	return ret;
}

int nextChildidx(int* childArr){
    int ret = 0;
    while(childArr[ret]!=-1){
        ret++;
    }
    return ret;
}

struct Node{
    int name;
	int child[31];
};

Node DirArr[50000];
int nodecnt;
Node* root;

pair<Node*,int> getNode(char name[NAME_MAXLEN + 1]) {
	DirArr[nodecnt].name = nameToint(name);
	for(int i=0;i<31;i++)DirArr[nodecnt].child[i] = -1;
	pair<Node*,int> ret = {&DirArr[nodecnt],nodecnt};
	nodecnt++;
	return ret;
}

int getNode(int name) {
	DirArr[nodecnt].name = name;
	for(int i=0;i<31;i++)DirArr[nodecnt].child[i] = -1;
	int ret = nodecnt;
	nodecnt++;
	return ret;
}

int getSize(Node* node){
	int sum = 1;
	for(int i=0;i<31;i++) {
        if(node->child[i]==-1) continue;
        sum+=getSize(&DirArr[node->child[i]]);
    }
    return sum;
}

int deepcopy(Node* node){
	int ret = getNode(node->name);
	for(int i=0;i<31;i++) {
        if(node->child[i]==-1) continue;
        DirArr[ret].child[nextChildidx(DirArr[ret].child)] = deepcopy(&DirArr[node->child[i]]);
    }
    return ret;
}

int finddir(char path[PATH_MAXLEN + 1], int patharr[400]){
    int size = 0;
    istringstream pathstream(path);
	string temp;
	while(getline(pathstream,temp,'/')) {
        patharr[size] = (nameToint(temp.c_str()));
        size++;
    }
	return size;
}

void init(int n) {
    nodecnt = 0;
	root = getNode("/").first;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    int pathV[400];
	int pathN = finddir(path,pathV);
	Node* parent = root;
	for(int i=0;i<pathN;i++){
		for(int j=0;j<31;j++){
            if(parent->child[j]==-1) continue;
			if(DirArr[parent->child[j]].name==pathV[i]){
				parent = &DirArr[parent->child[j]];
				break;
			}
		}
	}
	parent->child[nextChildidx(parent->child)] = (getNode(name).second);
	return;
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	int pathV[400];
	int pathN = finddir(path,pathV);
	Node* parent = root;
	for(int i=0;i<pathN-1;i++){
		for(int j=0;j<31;j++){
            if(parent->child[j]==-1) continue;
			if(DirArr[parent->child[j]].name==pathV[i]){
				parent = &DirArr[parent->child[j]];
				break;
			}
		}
	}
	for(int i=0;i<31;i++){
        if(parent->child[i]==-1) continue;
		if(DirArr[parent->child[i]].name==pathV[pathN-1]){
			parent->child[i] = -1;
			break;
		}
	}
	return;
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	int pathV[2][400]; int pathN[2];
	pathN[0] = finddir(srcPath,pathV[0]);
    pathN[1] = finddir(dstPath,pathV[1]);
	Node* parent[2];
	for(int s=0;s<2;s++){
		parent[s] = root;
		for(int i=0;i<pathN[s];i++){
			for(int j=0;j<31;j++){
                if(parent[s]->child[j]==-1) continue;
				if(DirArr[parent[s]->child[j]].name==pathV[s][i]){
					parent[s] = &DirArr[parent[s]->child[j]];
					break;
				}
			}
		}
	}

	parent[1]->child[nextChildidx(parent[1]->child)]=(deepcopy(parent[0]));
	return;
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    int pathV[2][400]; int pathN[2];
	pathN[0] = finddir(srcPath,pathV[0]);
    pathN[1] = finddir(dstPath,pathV[1]);
	Node* parent[2];
	for(int s=0;s<2;s++){
		if(s==0) pathN[s]--;
		parent[s] = root;
		for(int i=0;i<pathN[s];i++){
			for(int j=0;j<31;j++){
                if(parent[s]->child[j]==-1) continue;
				if(DirArr[parent[s]->child[j]].name==pathV[s][i]){
					parent[s] = &DirArr[parent[s]->child[j]];
					break;
				}
			}
		}
	}
	for(int i=0;i<31;i++){
        if(parent[0]->child[i]==-1) continue;
		if(DirArr[parent[0]->child[i]].name == pathV[0][pathN[0]]){
			parent[1]->child[nextChildidx(parent[1]->child)] = (parent[0]->child[i]);
			parent[0]->child[i] = -1;
			break;
		}
	}

	return;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	int pathV[400];
	int pathN = finddir(path,pathV);
	Node* parent = root;
	for(int i=0;i<pathN;i++){
		for(int j=0;j<31;j++){
            if(parent->child[j]==-1)continue;
			if(DirArr[parent->child[j]].name==pathV[i]){
				parent = &DirArr[parent->child[j]];
				break;
			}
		}
	}
	return getSize(parent)-1;
}


//////////////////////////////////////////////////

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}
	}

	return isAccepted;
}


int main(void) {

	int test, T;
	int n, m;

	// freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}