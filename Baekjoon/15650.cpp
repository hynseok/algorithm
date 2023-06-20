#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<int> index;
    vector<int> v;

    for(int i=1;i<=N;i++)
    {
        index.push_back(i);
    }

    for(int i=0;i<M;i++)
    {
        v.push_back(1);
    }
    for(int i=0;i<N-M;i++)
    {
        v.push_back(0);
    }

    do{
        for(int i=0;i<N;i++)
        {
            if(v[i]==1)cout<<index[i]<<' ';
        }
        cout<<'\n';
    }while(prev_permutation(v.begin(),v.end()));

    return 0;
}