#include <bits/stdc++.h>
using namespace std;

int first_map[8][8] = {0, };
int find_map[8][8] = {0, };
int N, M;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<pair<int,int> > virus;

void bfs()
{

    queue <pair<int,int> > q;
    for(auto v:virus){q.push(v);}

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nexty = y + dy[i];
            int nextx = x + dx[i];

            if(nexty<0||nexty>=N||nextx<0||nextx>=M||find_map[nexty][nextx])continue;
            q.push(make_pair(nexty,nextx));
            find_map[nexty][nextx] = 2;

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    int temp;
    int ans = 0;
    int tans;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>first_map[i][j];
            if(first_map[i][j]==2)
            {
                virus.push_back(make_pair(i,j));
            }
        }
    }
    
    for(int i1=0;i1<N;i1++)
    {
        for(int j1=0;j1<M;j1++)
        {
            if(first_map[i1][j1]!=0) continue;
            for(int i2=0;i2<N;i2++)
            {
                for(int j2=0;j2<M;j2++)
                {
                    if(i1==i2&&j1==j2) continue;
                    if(first_map[i2][j2]!=0) continue;
                    for(int i3=0;i3<N;i3++)
                    {
                        for(int j3=0;j3<M;j3++)
                        {
                            if(i2==i3&&j2==j3) continue;
                            if(i1==i3&&j1==j3) continue;
                            if(first_map[i3][j3]!=0) continue;

                            for(int y=0;y<N;y++)
                            {
                                for(int x=0;x<M;x++)
                                {
                                    find_map[y][x] = first_map[y][x];
                                }
                            }
                            find_map[i1][j1] = 1;
                            find_map[i2][j2] = 1;
                            find_map[i3][j3] = 1;
                            
                            bfs();

                            tans = 0;
                            for(int y=0;y<N;y++)
                            {
                                for(int x=0;x<M;x++)
                                {
                                    if(find_map[y][x]==0)tans++;
                                }
                            }

                            if(ans<tans) ans = tans;
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}