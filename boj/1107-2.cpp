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
    int ans = abs(N-100); int Tans[3];
    for(int i=0;i<M;i++)
    {
        int x;
        cin>>x;
        deny[x]=1;
    }


    for(int i=0;i<=999999;i++)
    {
        int temp;
        if(!Denied(i))
        {
            temp = Count(i) + abs(i-N);
            if(ans>temp) ans = temp;
        }
    }
    
    cout<<ans;
    return 0;
}