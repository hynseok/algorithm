#include <bits/stdc++.h>
using namespace std;
#define MAX 16

int N;
vector<pair<int,int>> List;
vector<int> Cost;

int ans = 0;

void DFS(int cnt)
{
    if(cnt==N)
    {
        int sum=0;
        for(int i=0;i<Cost.size();i++)
        {
            sum += Cost[i];
        }
        ans = max(ans,sum);
        return;
    }

    for(int i=cnt;i<N;i++)
    {
        int day = List[i].first;
        int cost = List[i].second;
        
        if(i+day>N&&i+1<=N)
        {
            DFS(i+1);
            continue;
        }
        Cost.push_back(cost);
        DFS(i+day);
        Cost.pop_back();
        
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int day, cost;
        cin>>day>>cost;
        List.push_back({day,cost});
    }

    DFS(0);
    cout<<ans;
}