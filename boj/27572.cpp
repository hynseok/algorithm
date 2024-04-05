#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

struct AC{
    int start;
    int end;
    int t;
    int cost;
};

int N, M;
int barn[101];
int ans = INF;
vector<AC> AClist;

int isSat(int ACswitch){
    int Tbarn[101];
    for(int i=1;i<=100;i++){
        Tbarn[i] = barn[i]; 
    }
    int costsum = 0;
    for(int i=1;i<=100;i++){
        for(int j=0;j<M;j++){
            if(ACswitch&(1<<j)&&AClist[j].start<=i&&AClist[j].end>=i) Tbarn[i]-=AClist[j].t;
        }
    }
    for(int j=0;j<M;j++){
        if(ACswitch&(1<<j))costsum += AClist[j].cost;
    }
    for(int i=1;i<=100;i++){
        if(Tbarn[i]>0) return -1;
    }

    return costsum;
}

void make(int ACswitch, int cnt){
    if(cnt==M){
        int ret = isSat(ACswitch);
        if(ret!=-1){
            if(ans>ret) ans = ret;
        }
        return;
    }
    make((ACswitch<<1)+1,cnt+1);
    make((ACswitch<<1),cnt+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;

    for(int i=0;i<N;i++){
        int a, b, c;
        cin>>a>>b>>c;
        for(int i=a;i<=b;i++){
            barn[i] = c;
        }
    }
    for(int i=0;i<M;i++){
        int a, b, p, m;
        cin>>a>>b>>p>>m;
        AClist.push_back({a,b,p,m});
    }
    make(0,0);
    cout<<ans;
    return 0;
}