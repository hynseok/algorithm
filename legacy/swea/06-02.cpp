#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int dp[101][1001];
    int W[101];
    int val[101];
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        memset(dp,0,sizeof(dp));
        memset(W,0,sizeof(W));
        memset(val,0,sizeof(val));
        int N, K;
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            int w, v;
            cin>>w>>v;
            W[i] = w;
            val[i] = v;
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(j-W[i]>=0)dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+val[i]);
                else dp[i][j] = dp[i-1][j];
            }
        }

        cout<<'#'<<tc<<' '<<dp[N][K]<<'\n';

    }
    return 0;
}