#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}

int S(vector<int> v)
{
    double ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans+=v[i];
    }
    return (int)floor(ans/v.size()+0.5);
}

int J(vector<int> v)
{
    return v[v.size()/2];
}

int C(vector<int> v)
{
    vector<pair<int,int>> c1;

    for(int i=0;i<v.size();i++)
    {
        if(c1.empty())
            c1.push_back(make_pair(v[i],1));
        else
        {
        if(v[i]==c1.back().first)
            c1.back().second++;
        else
            c1.push_back(make_pair(v[i],1));
        }
    }

    sort(c1.begin(),c1.end(),compare);

    if(c1[0].second==c1[1].second)
        return c1[1].first;
    return c1[0].first;
}

int B(vector<int> v)
{
    return v.back()-v.front();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> v1;
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    sort(v1.begin(),v1.end());

    cout<<S(v1)<<'\n';
    cout<<J(v1)<<'\n';
    cout<<C(v1)<<'\n';
    cout<<B(v1)<<'\n';


    return 0;
}