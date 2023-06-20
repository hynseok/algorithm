#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<pair<int,int>> v;
    int N;
    cin>>N;
    int t1, t2;
    for(int i=0;i<N;i++)
    {
        cin>>t1>>t2;
        v.push_back(make_pair(t1,t2));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<N;i++)
    {
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }



}