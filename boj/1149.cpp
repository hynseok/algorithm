#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> price;
int visited[1001]={0, };
int N;
int ans = 999999;

void DFS(int cnt,int rgb)//r=0 g=1 b=2
{
    if(cnt==N)
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum += price[i];
        }
        if(ans>sum)ans=sum;
        return ;
    }
    for(int i=cnt;i<N;i++)
    {
        if(visited[i]==1)continue;

        int min=999999; int tok=0; int idx;
        for(int j=0;j<3;j++)
        {
            if(j==rgb) continue;
            if(min>v[i][j]){min = v[i][j];idx=j;}
            if(min==v[i][j]) tok=1;
        }
        if(tok==1)
        {
            for(int j=0;j<3;j++)
            {
                if(j==rgb) continue;
                else
                {
                    price.push_back(v[i][j]);
                    visited[i]=1;
                    DFS(cnt+1,j);
                    price.pop_back();
                    visited[i]=0;
                }
            }
        }
        else
        {
            price.push_back(min);
            visited[i]=1;
            DFS(cnt+1,idx);
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
        vector<int> temp;
        for(int i=0;i<3;i++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }

    for(int i=0;i<3;i++)
    {
        price.push_back(v[0][i]);
        visited[0]=1;
        DFS(1,i);
        visited[0]=0;
        price.pop_back();
    }
    
}