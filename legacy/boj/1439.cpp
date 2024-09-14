#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin>>s;
    int tok, ans=1;
    for(int i=0;i<s.size();i++)
    {
        if(i==0)tok=s[i];
        else
        {
            if(tok!=s[i])
            {
                ans++;
                tok=s[i];
            }
        }
    }
    cout<<ans/2;
}