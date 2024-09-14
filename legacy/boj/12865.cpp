#include <bits/stdc++.h>
using namespace std;

int N, K, ans=0;
vector<pair<int,int> > List;
vector<pair<int,int> > Bag;
int visited[101];

void DFS(int weightsum, int valuesum)
{
    if(weightsum>K)
    {
        valuesum-=Bag.back().second;
        if(ans<valuesum) ans = valuesum;
        return;
    }
    if(weightsum==K)
    {
        if(ans<valuesum) ans = valuesum;
        return;
    }

    for(int i=0;i<List.size();i++)
    {
        if(visited[i]==1) continue;

        int nowweight = List[i].first;
        int nowvalue = List[i].second;

        Bag.push_back(make_pair(nowweight,nowvalue));
        visited[i]=1;
        DFS(weightsum+nowweight,valuesum+nowvalue);
        Bag.pop_back();
        visited[i]=0;
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    cin>>N>>K;

    for(int i=0;i<N;i++)
    {
        int weight, value;
        cin>>weight>>value;

        List.push_back(make_pair(weight, value));
    }
    DFS(0,0);
    cout<<ans<<'\n';
    return 0;
}