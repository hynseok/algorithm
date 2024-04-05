#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    string S, ans;
    int alpha[26]={0, };
    cin>>S;
    for(int i=0;i<S.size();i++)
    {
        alpha[S[i]-'A']++;
    }

    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if(alpha[i]%2==1)cnt++;
    }
    
    if(cnt>1)
    {
        cout<<"I'm Sorry Hansoo";
        return 0;
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<alpha[i]/2;j++)
        {
            ans+=i+'A';
        }
    }
    for(int i=0;i<26;i++)
    {
        if(alpha[i]%2) ans+=i+'A';
    }
    for(int i=25;i>=0;i--)
    {
        for(int j=0;j<alpha[i]/2;j++)
        {
            ans+=i+'A';
        }
    }

    cout<<ans<<'\n';

    return 0;
}

