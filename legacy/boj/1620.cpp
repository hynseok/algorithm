#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;

    cin>>N>>M;
    string S[100001];
    map<string,int> m;
    for(int i=0;i<N;i++)
    {
        string temp;
        cin>>temp;
        S[i]=temp;
        m.insert(make_pair(temp,i+1));
    }

    for(int i=0;i<M;i++)
    {
        string P;
        cin>>P;
        if(isdigit(P[0]))
        {
            cout<<S[stoi(P)-1]<<'\n';
        }
        else
        {
            cout<<m[P]<<'\n';
        }
    }
    return 0;
}