#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> vec;

void print()
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';

    }
    cout<<'\n';
}

void dfs(int cnt)
{
    if(cnt==M)
    {
        print();
        return;
    }

    for(int i=1;i<=N;i++)
    {
    
        if(!vec.empty())
        {
            if(vec.back()>i)continue;
        }
        vec.push_back(i);
        dfs(cnt+1);
        vec.pop_back();
            
        
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    cin>>N>>M;
    dfs(0);
    return 0;
}