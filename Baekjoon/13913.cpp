#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100004];
int prevArr[100004];
vector<int> ans;
int ans2;
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
            int idx = K;
            
            while(idx!=N)
            {
                ans.push_back(idx);
                idx = prevArr[idx];
            }
            ans.push_back(N);
            ans2 = cnt;
            break;
        }

        for(int i=0;i<3;i++)
        {
            int nx;
            if(i==0) nx=x+1;
            if(i==1) nx=x-1;
            if(i==2) nx=x*2;

            if(nx<0||nx>100000) continue;
            if(visited[nx]) continue;
            visited[nx] = 1;
            q.push(make_pair(nx,cnt+1));
            prevArr[nx] = x;
        }

    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>K;
    bfs(N);

    cout<<ans2<<'\n';
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<' ';
    }cout<<'\n';
    return 0;
}