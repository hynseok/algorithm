#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int A[54][54];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int visited[54][54];
int unionnum=0;
int ans = 0;
vector<pair<int,int> > Index[1500];

void indexclear()
{
    for(int i=0;i<1500;i++)
    {
        Index[i].clear();
    }
}

bool isbound(int a, int b)
{
    int dist = abs(b-a);
    if(dist>=L&&dist<=R) return true;
    return false;
}

bool dfs(int y, int x)
{
    visited[y][x] = 1;
    int tok = 0;
    for(int i=0;i<4;i++)
    {
        int nexty = y + dy[i];
        int nextx = x + dx[i];

        if(nexty<0||nexty>=N||nextx<0||nextx>=N||visited[nexty][nextx]) continue;
        if(!isbound(A[y][x],A[nexty][nextx])) continue;
        
        tok=1;
        Index[unionnum].push_back(make_pair(nexty,nextx));
        dfs(nexty,nextx);
    }

    if(tok==1) return true;
    return false;
}

bool Go()
{
    int tok = 0;
    unionnum = 0;
    indexclear();
    fill(&visited[0][0],&visited[53][54],0);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]==0)
            {
                if(dfs(i,j))
                {
                    int sum = 0;
                    sum += A[i][j];
                    tok=1;
                    for(int k=0;k<Index[unionnum].size();k++)
                    {
                        sum += A[Index[unionnum][k].first][Index[unionnum][k].second];
                    }
                    int next = sum/(Index[unionnum].size()+1);
                    A[i][j] = next;
                    for(int k=0;k<Index[unionnum].size();k++)
                    {
                        A[Index[unionnum][k].first][Index[unionnum][k].second] = next; 
                    }
                    unionnum++;
                } 
            }
        }
    }

    if(tok==1) 
    {
        ans++;
        return true;
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>L>>R;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>A[i][j];
        }
    }

    while(true)
    {
        if(!Go())break;
    }

    cout<<ans<<'\n';
    

    return 0;
}