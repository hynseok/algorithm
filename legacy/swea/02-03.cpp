#include <bits/stdc++.h>
using namespace std;
#define NUM 1000000007

long long dp[10001][16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        string S;
        cin>>S;
        int N = S.size();

        dp[0][1] = 1;
        for(int j=2;j<=15;j++){
            dp[0][j] = 0;
        }

        //j day
        for(int j=1;j<=N;j++){
            int idx = S[j-1]-'A';
            int M = 1<<idx;
            int sum=0;

            //k curr, l prev
            for(int k=1;k<=15;k++){
                for(int l=1;l<=15;l++){
                    if((k&l)&&(k&M)) {
                        dp[j][k] += (dp[j-1][l])%NUM;
                        dp[j][k] %= NUM;
                    }   
                }
                dp[j][k] %= NUM;
            }

        }

        for(int j=1;j<=15;j++){
            ans+=(dp[N][j]%NUM);
            ans%=NUM;
        }ans%=NUM;
        
        cout<<"#"<<i<<' '<<ans<<'\n';

    }

    return 0;
}