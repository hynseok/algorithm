#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;   
    vector <int> p;
    int idx[1000001];

    cin >> N;

    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        idx[i]=tmp;
        p.push_back(tmp);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    
    for(int i=0;i<N;i++)
    {
        cout<<lower_bound(p.begin(),p.end(),idx[i])-p.begin()<<' ';
    }

    return 0;
}