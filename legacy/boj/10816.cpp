#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    map<int, int> ma1;
    int N, M, temp;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin>>temp;

        if(ma1.find(temp)==ma1.end())
        {
            ma1.insert(make_pair(temp,1));
        }
        else
        {
            ma1[temp]++;
        }
    }

    cin >> M;
    
    for(int i=0;i<M;i++)
    {
        cin >> temp;
        
        if(ma1.find(temp)!=ma1.end())
        {
            cout<<ma1[temp]<<' ';
        }
        else
            cout<<0<<' ';
    }
}