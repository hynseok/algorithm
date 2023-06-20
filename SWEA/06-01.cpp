#include <bits/stdc++.h>
using namespace std;
int dp[1004][1004];
string A, B;
int T;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        memset(dp,0,sizeof(dp));
        cin>>A>>B;
        A = "0" + A;
        B = "0" + B;
        int n = A.length();
        int m = B.length();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0; continue;
                }
                if(A[i]==B[j]) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        cout<<'#'<<tc<<' '<<dp[n-1][m-1]<<'\n';
    }

    return 0;
}