#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
bool compare(pair<ui,ui> p1, pair<ui,ui> p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    vector<pair<ui,ui>> v;

    cin>>N;
    for(int i=0;i<N;i++)   
    {
        ui Ta, Tb;
        cin>>Ta>>Tb;
        v.push_back(make_pair(Ta,Tb));
    }

    sort(v.begin(),v.end(),compare);

    pair<ui,ui> time;
    time = v[0];
    int ans = 1;
    for(int i=1;i<N;i++)
    {
        if(v[i].first>=time.second)
        {
            time = v[i];
            ans++;
        }
    
    }
    cout<<ans;

    return 0;
}