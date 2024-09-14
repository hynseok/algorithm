#include <bits/stdc++.h>
using namespace std;
int N;
int idx, L, R;
char Data;
struct Node{
    char data;
    Node* left = nullptr;
    Node* right = nullptr;
};

void inorder(Node* root){
    if(root->left) inorder(root->left);
    cout<<root->data;
    if(root->right) inorder(root->right);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=1;i<=10;i++){
        cin>>N;
        Node* treeArr[101];
        for(int i=0;i<=N;i++) treeArr[i] = new Node; 
        for(int j=0;j<(N/2)-1;j++){
            cin>>idx>>Data>>L>>R;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
            treeArr[idx]->right = treeArr[R];
        }
        if(N%2==1){
            cin>>idx>>Data>>L>>R;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
            treeArr[idx]->right = treeArr[R];
        }
        else{
            cin>>idx>>Data>>L;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
        }
        for(int j=0;j<N-(N/2);j++){
            cin>>idx>>Data;
            treeArr[idx]->data = Data;
        }
        cout<<"#"<<i<<" ";
        inorder(treeArr[1]);
        cout<<'\n';
    }
    return 0;
}
