#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c;
    int X;
    char S[100]={};
    cin>>a>>b>>c;
    X = a*b*c;
    sprintf(S,"%d",X);
    int ans[11]={0, };
    for(int i=0;i<100;i++)
    {
        ans[S[i]-'0']++;
    }
    for(int i=0;i<=9;i++)
    {
        cout<<ans[i]<<'\n';

    }

}