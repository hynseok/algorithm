#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    string S;
    getline(cin,S);
    for(int i=0;i<S.size();i++)
    {
        if(S[i]==' ') continue;
        if(isdigit(S[i])) continue;
        if(S[i]>=65&&S[i]<=90)
        {
            for(int j=0;j<13;j++)
            {
                S[i]++;
                if(S[i]>90)S[i]=65;
            }
        }
        if(S[i]>=97&&S[i]<=122)
        {
            for(int j=0;j<13;j++)
            {
                S[i]++;
                if(S[i]>122)S[i]=97;
            }
        }
    }
    cout<<S;
    return 0;
}