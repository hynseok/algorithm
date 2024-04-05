#include <bits/stdc++.h>
using namespace std;

int deny[11] = {0, };

int Count(int N)
{
    if(N==0)return 1;

    int count=0;
    while(N!=0)
    {
        N/=10;
        count++;
    }
    return count;
}

bool Denied(int N)
{
    string S = to_string(N);
    for(int i=0;i<S.size();i++)
    {
        
        if(deny[S[i]-'0']==1) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int ans=999999, Tans[3];
    for(int i=0;i<M;i++)
    {
        int x;
        cin>>x;
        deny[x]=1;
    }

    Tans[0] = N-100;
    if(Tans[0]<0) Tans[0] = -Tans[0];

    int X=999999;
    for(int i=0;i<=N;i++)
    {
        if(!Denied(i)) X=i;
    }
    if(N-X<0)
    {
        Tans[1] = Count(X) + (X-N);
    }
    else Tans[1] = Count(X) + (N-X);
    if(X==999999)Tans[1]=999999;

    X=999999;
    for(int i=600000;i>=N;i--)
    {
        if(!Denied(i)) X=i;
    }
    if(X-N<0)
    {
        Tans[2] = Count(X) + (N-X);
    }
    else Tans[2] = Count(X) + (X-N);
    if(X==999999)Tans[2]=999999;

    for(int i=0;i<3;i++)
    {
        if(ans>Tans[i])ans=Tans[i];
    }
    cout<<ans;
 
    return 0;
}