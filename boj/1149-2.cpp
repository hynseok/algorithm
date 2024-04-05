#include <bits/stdc++.h>
using namespace std;

struct st
{
    int p;
    int color;//r=0 g=1 b=2
};
vector<vector<st>> v;
vector<st> price;
int visited[1001]={0, };
int N;
int ans = 999999;

void DFS(int cnt)//r=0 g=1 b=2
{
    if(cnt==N)
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum += price[i].p;
        }
        if(ans>sum)ans=sum;
        return ;
    
    }
    for(int i=0;i<=N;i++)
    {
        if(visited[i]==1) continue;
        for(int j=0;j<3;j++)
        {
            if(!price.empty())
            {
                if(price.back().color==v[i][j].color)continue;
            }
            st temp;
            temp.p = v[i][j].p; temp.color = v[i][j].color;
            price.push_back(temp);
            visited[i]=1;
            DFS(cnt+1);
            price.pop_back();
            visited[i]=0;
        }
        
    }

}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        vector<st> temp;
        for(int i=0;i<3;i++)
        {
            st tst; 
            cin>>tst.p; tst.color=i;
            temp.push_back(tst);
        }
        v.push_back(temp);
    }
    DFS(0);

    cout<<ans;

    
}