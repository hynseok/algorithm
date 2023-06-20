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

int Graph[27][27] = {0, };
int visited[27] = {0, }; 
int N;

void preorder(int node)
{
    visited[node]=1;
    cout<<iTOc(node);
    for(int i=1;i<=N;i++)
    {
        if(Graph[node][i]==1&&visited[i]==0)
        {
            preorder(i);
        }
    }
}

int tok[27] = {0, };
void inorder(int node)
{
    
    for(int i=1;i<=N;i++)
    {
        if(Graph[node][i]==1)
        {
            tok[node]=-1;
            inorder(i);
        }
    }
    if(tok[node]==0)
    {
        visited[node] = 1;
    }
}

void postorder(int node)
{

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char temp1;
        cin>>temp1;
        int temp_to_int1 = cTOi(temp1);
        
        for(int j=0;j<2;j++)
        {
            char temp2;
            cin>>temp2;
            if(temp2=='.')continue;
            int temp_to_int2 = cTOi(temp2);
            Graph[temp_to_int1][temp_to_int2] = 1;
            Graph[temp_to_int2][temp_to_int1] = 1;
        }
    }

    preorder(1);
    memset(visited,0,sizeof(int)*27);

    int leftidx = 0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(Graph[i][j]==1)
            {
                leftidx=j;
                break;
            }
        }
    }


}