    #include <bits/stdc++.h>
    using namespace std;

    int N, M;
    int Map[101][101]={0, };
    int visited[101]={0, };
    int ans;

    struct pos
    {
        int x;
        int length;
    };

    int main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        for(int i=1;i<=100;i++)
        {
            for(int j=i+1;j<=i+6;j++)
            {
                if(j>100)break;
                Map[i][j]=1;
            }
        }

        cin>>N>>M;
        for(int i=0;i<N+M;i++)
        {
            int tx, ty;
            cin>>tx>>ty;
            Map[tx][ty] = 2;
        }  

        queue<pos> Q;
        pos start;
        start.x=1; start.length=0;
        visited[start.x]=1;
        Q.push(start);

        while(!Q.empty())
        {
            pos temp;
            temp = Q.front();
            Q.pop();
            if(temp.x==100)
            {
                ans = temp.length;
                break;
            }
            for(int i=temp.x;i<=100;i++)
            {
                if(Map[temp.x][i]>0&&visited[i]==0)
                {
                    pos next;
                    next.x = i; next.length = temp.length;
                    if(Map[temp.x][i]==1) next.length++;
                    Q.push(next);
                }
            }
        }

        
        cout<<ans;
        

    }