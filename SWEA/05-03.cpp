#include <bits/stdc++.h>
using namespace std;

int N;
int d[100001], p[100001][21];
bool visited[100001];
vector<vector<int> > tree;

int lca(int x, int y){
    if(d[y]>d[x])swap(x,y);
    for(int i=19;i>=0;i--){
        if((d[x]-d[y])>=(1<<i))x = p[x][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(p[x][i]!=p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        tree.clear();
        memset(visited,0,sizeof(visited));
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));

        cin>>N;
        tree.resize(N+1);

        int pidx;
        for(int i=1;i<N;i++){
            cin>>pidx;
            tree[pidx-1].push_back(i);
        }

        queue<pair<int,int> > dq;
        dq.push(make_pair(0,0));
        visited[0] = true;

        while(!dq.empty()){
            int curr = dq.front().first;
            int depth = dq.front().second;
            dq.pop();
            d[curr] = depth;

            for(int i=0;i<tree[curr].size();i++){
                int next = tree[curr][i];
                if(visited[next])continue;
                visited[next] = true;
                p[next][0] = curr;
                dq.push(make_pair(next,depth+1));
            }
        }
        
        for(int i=1;i<=20;i++){
            for(int j=0;j<N;j++){
                p[j][i] = p[p[j][i-1]][i-1];
            }
        }

        long long ans = 0;
        memset(visited,0,sizeof(visited));
        vector<int> v;
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            v.push_back(curr);
            for(int i=0;i<tree[curr].size();i++){
                int next = tree[curr][i];
                if(visited[next])continue;
                visited[next] = true;
                q.push(next);
            }
        }

        for(int i=0;i<N-1;i++){
            int LCA = lca(v[i],v[i+1]);
            long long a = d[v[i]] - d[LCA];
            long long b = d[v[i+1]] - d[LCA];
            ans+= (a+b);
        }

        cout<<'#'<<tc<<' '<<ans<<'\n';
    }

    return 0;
}