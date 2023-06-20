#include <bits/stdc++.h>
using namespace std;

bool VPS(string s)
{
    stack<char> Pair;
        
    for(int j=0;j<s.size();j++)
    {
        char tc;
        tc = s[j];
        if(tc==')')
        {
            if(Pair.empty())
                return 0;
            else
            {
                Pair.pop();
            }
        }
        else
            Pair.push(tc);
    }
    if(Pair.size()==0)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    int N;
    cin>> N;

    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        if(VPS(s))
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}