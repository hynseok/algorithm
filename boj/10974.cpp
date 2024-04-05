#include <bits/stdc++.h>
using namespace std;

vector<int> V;
int N;
int visited[9];

void DFS(int cnt)
{
    if(cnt==N)
    {
        for(int i=0;i<N;i++)
        {
            cout<<V[i]<<' ';
        }
        cout<<'\n';
    }

    for(int i=1;i<=N;i++)
    {
        if(visited[i]==1) continue;

        V.push_back(i);
        visited[i]=1;
        DFS(cnt+1);
        visited[i]=0;
        V.pop_back();
    }

}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;

    DFS(0);
    
}