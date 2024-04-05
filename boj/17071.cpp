#include <bits/stdc++.h>
using namespace std;

int N, K;
int visited[500004][2];

void BFS(int N)
{
    queue<pair<int,int> > Q;
    Q.push(make_pair(N,0));
    memset(visited,-1,sizeof(visited));

    while(!Q.empty())
    {
        int now = Q.front().first; 
        int time = Q.front().second;
        int nowK = K + time*(time+1)/2;
        Q.pop();

        //if(now<0||now>500000) continue;
        //if(visited[now][time%2]!=-1) continue;
        //visited[now][time%2] = time;
        
        if(nowK>500000)
        {
            cout<<-1<<'\n';
            break;
        }
        int next;
        for(int i=0;i<3;i++)
        {
            if(i==0)next = now +1; 
            if(i==1)next = now -1;
            if(i==2)next = now *2;

            if(next<0||next>500000) continue;
            if(visited[next][(time+1)%2]!=-1)continue;

            visited[next][(time+1)%2] = time;
            Q.push(make_pair(next,time+1));
        }   
        
    }

    /*
    bool tokken = false;
    for(int i=0;i<=500000;i++)
    {
        int nextK = K + (i*(i+1))/2;
        if(nextK>500000)break;
        if(visited[nextK][i%2]!=-1&&visited[nextK][i%2]<=i)
        {
            cout<<i<<'\n';
            tokken = true;
            break;
        }
    }

    if(!tokken)cout<<-1<<'\n'; 
    */

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>K;

    BFS(N);
    return 0;
}