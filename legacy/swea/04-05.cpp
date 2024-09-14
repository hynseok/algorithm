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

int nameToint(const char *src){
	int ret = 0;
	int len = mstrlen(src);
	int i = 0;
	for(;i<len;i++) ret = (ret<<5) | (src[i] - 'a' + 1);
	for(;i<6;i++) ret = (ret<<5);
	return ret;
}

struct Node{
    int name;
	vector<int> child;
};

Node DirArr[50000];
int nodecnt;
Node* root;

pair<Node*,int> getNode(char name[NAME_MAXLEN + 1]) {
	DirArr[nodecnt].name = nameToint(name);
	DirArr[nodecnt].child.clear();
	pair<Node*,int> ret = {&DirArr[nodecnt],nodecnt};
	nodecnt++;
	return ret;
}

int getNode(int name) {
	DirArr[nodecnt].name = name;
	DirArr[nodecnt].child.clear();
	int ret = nodecnt;
	nodecnt++;
	return ret;
}

int getSize(Node* node){
	int sum = 1;
	int childN = node->child.size();
	for(int i=0;i<childN;i++) sum+=getSize(&DirArr[node->child[i]]);
	return sum;
}

int deepcopy(Node* node){
	int ret = getNode(node->name);
	int childN = node->child.size();
	for(int i=0;i<childN;i++) DirArr[ret].child.push_back(deepcopy(&DirArr[node->child[i]]));
	return ret;
}

vector<int> finddir(char path[PATH_MAXLEN + 1]){
	istringstream pathstream(path);
	string temp;
	vector<int> ret;
	while(getline(pathstream,temp,'/')) ret.push_back(nameToint(temp.c_str()));
	return ret;
}

void init(int n) {
    nodecnt = 0;
	root = getNode("/").first;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    vector<int> pathV = finddir(path);
	int pathN = pathV.size();
	Node* parent = root;
	for(int i=0;i<pathN;i++){
		int childN = parent->child.size();
		for(int j=0;j<childN;j++){
			if(DirArr[parent->child[j]].name==pathV[i]){
				parent = &DirArr[parent->child[j]];
				break;
			}
		}
	}
	parent->child.push_back(getNode(name).second);
	return;
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	vector<int> pathV = finddir(path);
	int pathN = pathV.size();
	Node* parent = root;
	for(int i=0;i<pathN-1;i++){
		int childN = parent->child.size();
		for(int j=0;j<childN;j++){
			if(DirArr[parent->child[j]].name==pathV[i]){
				parent = &DirArr[parent->child[j]];
				break;
			}
		}
	}
	int childN = parent->child.size();
	for(int i=0;i<childN;i++){
		if(DirArr[parent->child[i]].name==pathV[pathN-1]){
			parent->child.erase(parent->child.begin()+i);
			break;
		}
	}
	return;
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	vector<int> pathV[2] = {finddir(srcPath),finddir(dstPath)};
	Node* parent[2];
	for(int s=0;s<2;s++){
		int pathN = pathV[s].size();
		parent[s] = root;
		for(int i=0;i<pathN;i++){
			int childN = parent[s]->child.size();
			for(int j=0;j<childN;j++){
				if(DirArr[parent[s]->child[j]].name==pathV[s][i]){
					parent[s] = &DirArr[parent[s]->child[j]];
					break;
				}
			}
		}
	}

	parent[1]->child.push_back(deepcopy(parent[0]));
	return;
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	vector<int> pathV[2] = {finddir(srcPath),finddir(dstPath)};
	Node* parent[2];
	int pathN[2];
	for(int s=0;s<2;s++){
		pathN[s] = pathV[s].size();
		if(s==0) pathN[s]--;
		parent[s] = root;
		for(int i=0;i<pathN[s];i++){
			int childN = parent[s]->child.size();
			for(int j=0;j<childN;j++){
				if(DirArr[parent[s]->child[j]].name==pathV[s][i]){
					parent[s] = &DirArr[parent[s]->child[j]];
					break;
				}
			}
		}
	}
	int childN = parent[0]->child.size();
	for(int i=0;i<childN;i++){
		if(DirArr[parent[0]->child[i]].name == pathV[0][pathN[0]]){
			parent[1]->child.push_back(parent[0]->child[i]);
			parent[0]->child.erase(parent[0]->child.begin()+i);
			break;
		}
	}

	return;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	vector<int> pathV = finddir(path);
	int pathN = pathV.size();
	Node* parent = root;
	for(int i=0;i<pathN;i++){
		int childN = parent->child.size();
		for(int j=0;j<childN;j++){
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