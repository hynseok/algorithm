#include <bits/stdc++.h>
using namespace std;

int stair[301];
int dp[301];
int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int tmp;
    stair[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin >> tmp;
        stair[i]=tmp;
    }

    dp[0]=0;
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];
    dp[3]=max(stair[1]+stair[3],stair[2]+stair[3]);
    for(int i=4;i<=N;i++)
    {
        dp[i]=max(dp[i-3]+stair[i-1]+stair[i],dp[i-2]+stair[i]);
    }

    cout<<dp[N];
    
    return 0;




}