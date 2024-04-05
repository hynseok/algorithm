#include <bits/stdc++.h>
using namespace std;

int Map[1004][1004]; //0=벽, 1=길, 2=불
int visited[1004][1004];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int R, C;
int ans;
pair<int,int> JI;
vector<pair<int,int> > FI;

int BFS(int jy, int jx)
{
    queue<pair<pair<int,int>,pair<int,int> > >Q; // <y정보, x정보>,<지훈인지,길이>;

    visited[jy][jx] = 1;
    for(int i=0;i<FI.size();i++)
    {
        Q.push(make_pair(make_pair(FI[i].first,FI[i].second),make_pair(0,0)));
    }
    Q.push(make_pair(make_pair(jy,jx),make_pair(1,0)));
    
    
    


    while(!Q.empty())
    {
        int nowy = Q.front().first.first; int nowx = Q.front().first.second;
        int tokji = Q.front().second.first; int dist = Q.front().second.second;
        
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nexty = nowy + dy[i]; int nextx = nowx + dx[i];
            
            if(tokji==1)
            {
                if(nexty<0||nextx<0||nexty>=R||nextx>=C)
                {
                    return dist+1;
                }
                if(Map[nexty][nextx]==0||Map[nexty][nextx]==2||visited[nexty][nextx]) continue;
                visited[nexty][nextx] = 1;
                Q.push(make_pair(make_pair(nexty,nextx),make_pair(1,dist+1)));
            }
            else if(tokji==0)
            {
                if(Map[nexty][nextx]==0||nexty<0||nextx<0||nexty>=R||nextx>=C||visited[nexty][nextx]||Map[nexty][nextx]==2) continue;
                Map[nexty][nextx] = 2;
                Q.push(make_pair(make_pair(nexty,nextx),make_pair(0,0)));
            }
        }

        
    }

    return -1;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>R>>C;

    string line;
    char info;

    fill(&Map[0][0],&Map[1003][1004],4); 
    for(int i=0;i<R;i++)
    {
        cin>>line;
        for(int j=0;j<C;j++)
        {
            info = line[j];
            if(info=='#') Map[i][j] = 0;
            if(info=='.') Map[i][j] = 1;
            if(info=='J') 
            {
                JI.first = i; JI.second = j;
                Map[i][j] = 1;
            }
            if(info=='F') 
            {
                FI.push_back(make_pair(i,j));
                Map[i][j] = 2;
            }
        }
    }

      
    ans = BFS(JI.first,JI.second);

    if(ans==-1)
    {
        cout<<"IMPOSSIBLE"<<'\n';
    }
    else
    {
        cout<<ans<<'\n';
    }

    return 0;
}