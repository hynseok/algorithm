#include <bits/stdc++.h>
using namespace std;

int P(int p)
{
    if(p==0)return 1;
    return p*P(p-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K, ans;

    cin>>N>>K;

    ans=P(N)/(P(N-K)*P(K));

    cout<<ans;
}