#include <iostream>
#include <vector>

using namespace std;

int n;
int q;

typedef struct node {
  int a;
  int parent;
  vector<int> children;
};

vector<node> tree;


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  cin >> n;

  // dummy data for index 0
  node dummy;
  tree.push_back(dummy);
  
  for(int i = 0; i < n; i++) {
    node temp;
    cin >> temp.a;
    tree.push_back(temp);
  }

  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].children.push_back(b);
    tree[b].parent = a;
  }

  
}