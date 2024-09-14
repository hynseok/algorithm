#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector <int> connect[100002];
int node_size[100002];

typedef struct node {
  int num;
  int parent;
  vector <int> children;
} Node;

Node Tree[100002];

void make_tree(Node *node, int parent) {
  for(int i = 0; i < connect[node->num].size(); i++) {
    if(connect[node->num][i] != parent) {
      node->children.push_back(connect[node->num][i]);
      Tree[connect[node->num][i]].parent = node->num;
      make_tree(&Tree[connect[node->num][i]], node->num);
    }
  }
}

void count_subtree_nodes(Node node) {
  node_size[node.num] = 1;
  for(int i = 0; i < node.children.size(); i++) {
    count_subtree_nodes(Tree[node.children[i]]);
    node_size[node.num] += node_size[node.children[i]];
  }
}

int main() {

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  
  cin >> N >> R >> Q;

  int v1, v2;
  for (int i = 0; i < N - 1; i++) {
    cin >> v1 >> v2;
    connect[v1].push_back(v2);
    connect[v2].push_back(v1);
  }

  for(int i = 0; i < 100001; i++) {
    Tree[i].num = i;
  }

  make_tree(&Tree[R], -1);
  count_subtree_nodes(Tree[R]);

  int q;
  for(int i = 0; i < Q; i++) {
    cin >> q;
    cout << node_size[q] << "\n";
  }
}