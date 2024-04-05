#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001] = {false};
int ans1=0, ans2=0;
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;

    while(!q.empty())
    {
        int qsize = q.size();
        for(int i=0;i<qsize;i++)
        {
            int now = q.front();
            q.pop();
            if(now==K) ans2++;
            visited[now] = true;

            int next;
            for(int j=0;j<3;j++)
            {
                if(j==0) next = now+1;
                if(j==1) next = now-1;
                if(j==2) next = now*2;

                if(next>100000||next<0||visited[next])continue;
                q.push(next);
            }
        }
        if(ans2!=0)return;
        ans1++;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>K;
    bfs(N);
    cout<<ans1<<'\n'<<ans2<<'\n';
    return 0;
}