#include <bits/stdc++.h>
using namespace std;

struct node
{
    int parent=-1;
    int depth=-1;
    vector<int> childnode;

};
vector<node> treev;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<=N;i++)
    {
        node temp;
        treev.push_back(temp);
    }
    treev[1].parent=0;
    treev[1].depth=0;
    for(int i=0;i<N-1;i++)
    {  
        int a, b;
        cin>>a>>b;
        if(treev[a].parent==-1)
        {
            treev[a].parent = b;
            treev[a].depth = treev[b].depth+1;
            treev[b].childnode.push_back(a);
        }
        else if(treev[b].parent==-1)
        {
            treev[b].parent = a;
            treev[b].depth = treev[a].depth+1;
            treev[a].childnode.push_back(b);
        }

    }
    for(int i=2;i<=N;i++)
    {
        cout<<treev[i].parent<<'\n';
    }

}