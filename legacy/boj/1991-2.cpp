#include <bits/stdc++.h>
using namespace std;

//1=A 2=B ...
int cTOi(char c)
{
    int i=c-64;
    return i;
}
char iTOc(int i)
{
    char c = i+64;
    return c;
}

struct node
{
    char data;
    node* left;
    node* right;
};

int N;

void preorder(node* root)
{
    cout<<root->data;
    if(root->left) preorder(root->left);
    if(root->right) preorder(root->right);
}

void inorder(node* root)
{
    if(root->left) inorder(root->left);
    cout<<root->data;
    if(root->right) inorder(root->right);
}

void postorder(node* root)
{
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    cout<<root->data;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    node* treeArr[N];

    for(int i=0;i<N;i++)
    {
        treeArr[i] = new node;
        treeArr[i]->data = iTOc(i+1);
    }

    for(int i=0;i<N;i++)
    {
        char temp1;
        cin>>temp1;
        int temp_to_int1 = cTOi(temp1)-1;

        char temp2;
        cin>>temp2;
        if(temp2=='.') treeArr[temp_to_int1]->left = NULL;
        else
        {
            int temp_to_int2 = cTOi(temp2)-1;
            treeArr[temp_to_int1]->left = treeArr[temp_to_int2];
        }

        char temp3;
        cin>>temp3;
        if(temp3=='.') treeArr[temp_to_int1]->right = NULL;
        else
        {
            int temp_to_int3 = cTOi(temp3)-1;
            treeArr[temp_to_int1]->right = treeArr[temp_to_int3];
        }    
    }

    preorder(treeArr[0]);
    cout<<'\n';
    inorder(treeArr[0]);
    cout<<'\n';
    postorder(treeArr[0]);
    


}