#include <bits/stdc++.h>
using namespace std;

vector<int> treev;
vector<pair<int,int>> input;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<=N;i++)
    {
        treev.push_back(-1);
    }
    treev[1]=0;
    for(int i=0;i<N-1;i++)
    {  
        int a, b;
        cin>>a>>b;
        if(treev[a]>-1)
        {
            treev[b] = a;
        }
        else if(treev[b]>-1)
        {
            treev[a] = b;
        }
        else
        {
            input.push_back({a,b});
        }

    }

    while(!input.empty())
    {
        int a, b;
        for(int i=0;i<input.size();i++)
        {
            a = input[i].first;
            b = input[i].second;
            if(treev[a]>-1)
            {
                treev[b] = a;
            }
            else if(treev[b]>-1)
            {
                treev[a] = b;
            }
            else continue;
            input.erase(input.begin()+i);
        }
        
    }
    for(int i=2;i<=N;i++)
    {
        cout<<treev[i]<<'\n';
    }
}