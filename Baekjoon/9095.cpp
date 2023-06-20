#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int dp[12];
    dp[1]=1; dp[2]=2; dp[3]=4;

    int T;
    cin>>T;

    for(int i=4;i<=11;i++)
    {
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }

    for(int i=0;i<T;i++)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }

    return 0;
}