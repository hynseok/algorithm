#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> S2;
    map<string,int> m;

    for(int i=0;i<N+M;i++)
    {
        string temp;
        cin>>temp;

        m[temp]++;
    }   

    for(auto iter : m)
    {
        if(iter.second>1)
        {
            S2.push_back(iter.first);        
        }
    }

    sort(S2.begin(),S2.end());

    cout<<S2.size()<<'\n';
    for(int i=0;i<S2.size();i++)
    {
        cout<<S2[i]<<'\n';
    }

    return 0;

}