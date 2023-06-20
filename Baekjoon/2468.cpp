    #include <bits/stdc++.h>
    using namespace std;

    int Map[101][101];
    int visited[101][101];
    int N;
    int num, ans=-1;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    void DFS(int deep, int nowx, int nowy)
    {
        visited[nowy][nowx] = 1;

        for(int i=0;i<4;i++)
        {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];

            if(nextx<0||nextx>=N||nexty<0||nexty>=N) continue;
            if(Map[nexty][nextx]<=deep) continue;
            if(visited[nexty][nextx]==1) continue;

            DFS(deep,nextx,nexty);
        }

        return;
    }

    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
        
        int maxheight = -1;

        cin>>N;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>Map[i][j];
                if(Map[i][j]>maxheight) maxheight = Map[i][j];
            }
        }

        for(int i=0;i<maxheight;i++)
        {
            num=0;
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++) visited[j][k] = 0;
            }

            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    if(visited[j][k]==0&&Map[j][k]>i)
                    {
                        num++;
                        DFS(i,k,j);
                    }
                }
            }

            if(ans<num) ans=num;

        }


        cout<<ans<<'\n';

        return 0;
    }