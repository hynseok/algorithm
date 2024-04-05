#include <bits/stdc++.h>
using namespace std;

int N, ans=0;
int num[1001];
int dp[1001];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
    }
    
    for(int i=1;i<=N;i++)
    {
        dp[i] = 1;
        for(int j=1;j<=i-1;j++)
        {
            if(num[i]>num[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans = max(dp[i],ans);
    }

    cout<<ans;


}