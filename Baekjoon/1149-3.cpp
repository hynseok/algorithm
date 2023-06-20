#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int price[1001][3];
    int dp[1001];
    int N;
    cin>>N;
    price[0][0] = 0; price[0][1] = 0; price[0][2] = 0;
    for(int i=1;i<=N;i++)
    {
        int cost[3];
        for(int j=0;j<3;j++)
        {
            cin>>cost[j];
        }
        price[i][0] = min(price[i-1][1]+cost[0],price[i-1][2]+cost[0]);
        price[i][1] = min(price[i-1][0]+cost[1],price[i-1][2]+cost[1]);
        price[i][2] = min(price[i-1][0]+cost[2],price[i-1][1]+cost[2]);
    }

    cout<<min(price[N][0],min(price[N][1],price[N][2]));

}