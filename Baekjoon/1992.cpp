#include <bits/stdc++.h>
using namespace std;

int Map[70][70];

void cut(int N, int a, int b)
{

    if(N==1)
    {
        cout<<Map[a][b];
        return;
    }

    vector<pair<int,int>> v;
    v.push_back({a,b});
    v.push_back({a,b+N/2});
    v.push_back({a+N/2,b});
    v.push_back({a+N/2,b+N/2});

    int check = Map[a][b];
    int diff = Map[a][b];

    for(int i=0;i<N;i++)
    {
        if(check!=diff)break;
        for(int j=0;j<N;j++)
        {
            if(check!=Map[a+i][b+j])
            {
                diff=Map[a+i][b+j];
                cout<<'(';
                for(int k=0;k<4;k++)cut(N/2,v[k].first,v[k].second);
                cout<<')';
                break;
            }
        }
    }

    if(check!=diff)return;
    else
    {
        if(check==1)cout<<1;
        else cout<<0;
    }
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%1d",&Map[i][j]);
        }
    }
    cut(N,1,1);
    return 0;
}