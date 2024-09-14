#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[101][100001]={0,};
int Weight[101]={0,};
int Value[101];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        int weight, value;
        cin>>weight>>value;
        Weight[i] = weight;
        Value[i] = value;
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=K;j++)
        {
            if(j-Weight[i]>=0)dp[i][j] = max(dp[i-1][j],dp[i-1][j-Weight[i]]+Value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[N][K]<<'\n';
    return 0;
}