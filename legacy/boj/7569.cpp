#include <bits/stdc++.h>
using namespace std;

struct pos
{
    int x;
    int y;
    int z;
};
int Map[101][101][101];
int M, N, H;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int result = 0;
queue<pos> Q;

bool checkMap()
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                if(Map[i][j][k]>result)result = Map[i][j][k];
                if(Map[i][j][k]==0)return false;
                
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>M>>N>>H;

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                int temp;
                cin>>temp;
                if(temp==1)
                {
                    pos position;
                    position.x=k; position.y=j; position.z=i;
                    Q.push(position);
                }
                Map[i][j][k]=temp;
            }
        }
    }

    if(checkMap())
    {
        cout<<0;
        return 0;
    }

    while(!Q.empty())
    {
        pos temp;
        temp = Q.front();
        Q.pop();
        
        for(int i=0;i<6;i++)
        {
            pos next;
            next.x=temp.x+dx[i]; next.y=temp.y+dy[i]; next.z=temp.z+dz[i];
            if(next.x>=0&&next.x<M&&next.y>=0&&next.y<N&&next.z>=0&&next.z<H)
            {
                if(Map[next.z][next.y][next.x]==0)
                {
                    Map[next.z][next.y][next.x]=Map[temp.z][temp.y][temp.x]+1;
                    Q.push(next);
                }
            }
        }
    }

    if(!checkMap())
    {
        cout<<-1;
        return 0;
    }
    else
    {
        cout<<result-1;
        return 0;
    }


}