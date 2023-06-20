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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=1;i<=10;i++){
        int flag = 0;
        cin>>N;
        Node* treeArr[201];
        for(int i=0;i<=N;i++) treeArr[i] = new Node; 
        for(int j=0;j<(N/2)-1;j++){
            cin>>idx>>Data>>L>>R;
            if(!(Data=='+'||Data=='-'||Data=='*'||Data=='/'))flag = 1;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
            treeArr[idx]->right = treeArr[R];
        }
        if(N%2==1){
            cin>>idx>>Data>>L>>R;
            if(!(Data=='+'||Data=='-'||Data=='*'||Data=='/'))flag = 1;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
            treeArr[idx]->right = treeArr[R];
        }
        else{
            flag = 1;
            cin>>idx>>Data>>L;
            treeArr[idx]->data = Data;
            treeArr[idx]->left = treeArr[L];
        }
        for(int j=0;j<N-(N/2);j++){
            cin>>idx>>Data;
            if((Data=='+'||Data=='-'||Data=='*'||Data=='/'))flag = 1;
            treeArr[idx]->data = Data;
        }
        cout<<"#"<<i<<" ";
        if(flag==1)cout<<0<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}
