#include <bits/stdc++.h>
using namespace std;

int N;
int scv[4]={0,};
int ans=987654321;
int combi3[6][3] = {{9,3,1},{9,1,3},{3,9,1},{1,9,3},{3,1,9},{1,3,9}};
int combi2[2][2] = {{9,3},{3,9}};
int combi1[1][1] = {9};

bool compare(int a, int b)
{
    return a>b;
}

void dfs(int count, int live)
{
    for(int i=0;i<3;i++)
    {
        cout<<scv[i]<<' ';
    }
    cout<<'\n';
    if(live==0)
    {
        if(ans>count) ans=count;
        return;
    }

    sort(scv,scv+3,compare);
    int dead = 0;   
    if(live==3)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++) scv[j] -= combi3[i][j];
        
            for(int j=0;j<3;j++) if(scv[j]<=0)dead++;
            
            dfs(count+1,live-dead);
            for(int j=0;j<3;j++) scv[j] += combi3[i][j];

        }
    }
    else if(live==2)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++) scv[j] -= combi2[i][j];

            for(int j=0;j<2;j++) if(scv[j]<=0)dead++;
            
            dfs(count+1,live-dead);
            for(int j=0;j<2;j++) scv[j] += combi2[i][j];

        }
    }
    else if(live==1)
    {
        scv[0] -= combi1[0][0];
        if(scv[0]<=0) dead++;
        
        dfs(count+1,live-dead);
        scv[0] += combi1[0][0];
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>scv[i];
    }

    dfs(0,N);

    cout<<ans;

    return 0;
}