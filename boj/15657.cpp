#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> output;
vector<int> num;

void dfs(int cnt)
{
    if(cnt==M)
    {
        for(int i=0;i<output.size();i++)
        {
            cout<<output[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(!output.empty())
        {
            if(output.back()>num[i]) continue;
        }
        output.push_back(num[i]);
        dfs(cnt+1);
        output.pop_back();
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        int temp; cin>>temp;   
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    dfs(0);
}