#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];

void bfs(int N)
{
    queue<pair<int,int> > q;
    q.push(make_pair(N,0));
    visited[N]=true;

    while(!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x==K)
        {
            cout<<cnt;
            break;
        }
        if(x+1>=0&&x+1<=100000)
        {
            if(!visited[x+1])
            {
                visited[x+1]=true;
                q.push(make_pair(x+1,cnt+1));
            }
        }
        if(x-1>=0&&x-1<=100000)
        {
            if(!visited[x-1])
            {
                visited[x-1]=true;
                q.push(make_pair(x-1,cnt+1));
            }
        }
        if(x*2>=0&&x*2<=100000)
        {
            if(!visited[x*2])
            {
                visited[x*2]=true;
                q.push(make_pair(x*2,cnt+1));
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>K;
    bfs(N);
    return 0;
}