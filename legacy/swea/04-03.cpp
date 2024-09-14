#include <bits/stdc++.h>
using namespace std;
int N;
int idx, L, R, ret;
string Data;
int iData;
struct Node{
    char data = 'x';
    int idata = -1;
    Node* left = nullptr;
    Node* right = nullptr;
};
int inorder(Node* root){
    if((root->data)=='+'){
        return inorder(root->left) + inorder(root->right);
    }   
    else if(root->data=='-'){
        return inorder(root->left) - inorder(root->right);
    }
    else if(root->data=='*'){
        return inorder(root->left) * inorder(root->right);
    }
    else if(root->data=='/'){
        return inorder(root->left) / inorder(root->right);
    }
    else{
        return root->idata;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=1;i<=10;i++){
        cin>>N;
        Node* treeArr[1001];
        for(int i=0;i<=N;i++) treeArr[i] = new Node; 
        for(int j=0;j<N;j++){
            cin>>idx;
            cin>>Data;
            if(Data=="+"||Data=="-"||Data=="*"||Data=="/"){
                cin>>L>>R;
                treeArr[idx]->data = Data[0];
                treeArr[idx]->left = treeArr[L];
                treeArr[idx]->right = treeArr[R];
            }
            else{
                iData = stoi(Data);
                treeArr[idx]->idata = iData;
            }
        }
        ret = inorder(treeArr[1]);
        cout<<"#"<<i<<" "<<ret<<'\n';
    }
    return 0;
}
