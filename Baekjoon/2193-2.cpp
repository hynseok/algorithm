#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    long long int dp[91];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 5;

    for(int i=6;i<=90;i++)
    {
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    

    cout<<dp[N];
    return 0;

}