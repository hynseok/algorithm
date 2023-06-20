#include <bits/stdc++.h>
using namespace std;

int N, M;
int gr[101][101] = {0, };
int visited[101] = {0, };
int ans = 0;

void search(int p)
{
    ans++;
    visited[p]=1;
    for(int i=1;i<=N;i++)
    {
        if(gr[p][i]==1&&visited[i]==0)
        {
            search(i);
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


   cin >> N >> M;


   for(int i=0;i<M;i++)
   {
        int t1, t2;
        cin>>t1>>t2;

        gr[t1][t2]=gr[t2][t1]=1;
   }

    search(1);



    cout<<ans-1<<'\n';
}