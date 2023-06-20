#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int start;
    int end;
    int cost;

    bool operator<(const Edge& e)
    const{
        return cost>e.cost;
    }
};
int parent[50001];
int N, M, ans;

int findparent(int x){
    if(x==parent[x]) return parent[x];
    else return x = findparent(parent[x]);
}

void Union(int x, int y){
    if(x>y) parent[x] = parent[y];
    else parent[y] = parent[x];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N>>M;
        priority_queue<Edge> pq;
        int s, e, c;
        for(int i=0;i<M;i++){
            cin>>s>>e>>c;
            Edge temp;
            temp.start = s; temp.end = e;
            temp.cost = c;
            pq.push(temp);
        }
        
        for(int i=0;i<N;i++){
            parent[i] = i;
        }

        ans = 0;
        while(!pq.empty()){
            Edge curr = pq.top();
            pq.pop();
            int x = findparent(curr.start);
            int y = findparent(curr.end);
            if(x==y) continue;
            ans += curr.cost;
            Union(x,y);
        }

        cout<<'#'<<tc<<' '<<ans<<'\n';
    }

    return 0;
}