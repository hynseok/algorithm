#include <bits/stdc++.h>
using namespace std;
#define MAX 9

vector<int> vec;
vector<vector<int>> V;
int Num[MAX];
int visited[MAX];
int N, M;

void DFS(int cnt)
{
    if(cnt==M)
    {
        for(int i=0;i<M;i++)
        {
            V.push_back(vec);
        }
    }

    for(int i=0;i<N;i++)
    {
        if(visited[i]==1)continue;

        vec.push_back(Num[i]);
        visited[i]=1;
        DFS(cnt+1);
        vec.pop_back();
        visited[i]=0;
    }


}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>Num[i];
    }

    DFS(0);
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<' ';
        }
        cout<<'\n';
    }
}