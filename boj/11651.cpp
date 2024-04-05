#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,x,y;
    cin >> N;
    vector<pair<int,int>> v1;
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }

    sort(v1.begin(),v1.end(),compare);

    for(int i=0;i<N;i++)
    {
        cout<<v1[i].first<<' '<<v1[i].second<<'\n';
    }

}