#include <bits/stdc++.h>
using namespace std;

int N;
int Map[21][21];
int visited[21][21]={0,};
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int ans = 0;
bool eat = false;
bool stop = false;
struct Shark
{
    int x;
    int y;
    int size;
    int eat;
    int d;
};

Shark start;

void bfs()
{
    queue<Shark> Q;
    Q.push(start);
    visited[start.y][start.x] = 1;
    int T;
    while(!Q.empty())
    {
        Shark temp;
        temp = Q.front();
        if(Map[temp.y][temp.x]>0&&Map[temp.y][temp.x]<temp.size&&T==temp.d)
        {
            if(start.y>temp.y||(start.y==temp.y&&start.x>temp.x))
            {
                start.y=temp.y;
                start.x=temp.x;
                continue;
            }
        }
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nextY = temp.y + dy[i];
            int nextX = temp.x + dx[i];
            if(nextX>=0&&nextX<N&&nextY>=0&&nextY<N)
            {
                if(visited[nextY][nextX]==0&&Map[nextY][nextX]<=temp.size)
                {
                    Shark next;
                    next.y = nextY; next.x = nextX; next.size = temp.size; next.eat = temp.eat; 
                    next.d = temp.d + 1;
                    if(temp.size>Map[nextY][nextX]&&Map[nextY][nextX]>0&&!eat)
                    {
                        T = temp.d+1;
                        eat = true;
                        ans += T;
                        start.d=0;
                        start.x = next.x; start.y = next.y;
                    }
                    else
                    {
                        Q.push(next);
                        visited[next.y][next.x]=1;
                    }
                    
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> Map[i][j];
            if(Map[i][j]==9)
            {
                start.y = i; start.x = j; start.d = 0;
                start.eat = 0; start.size = 2;
                Map[i][j]=0;
            }
        }
    }

    while(!stop)
    {
        for(int i=0;i<21;i++){ memset(visited[i],0,sizeof(int)*21);}
        bfs();
        if(eat)
        {
            eat = false;
            start.eat++;
            Map[start.y][start.x]=0;
            if(start.eat==start.size)
            {
                start.eat=0;
                start.size++;
            }
            start.d=0;
        }
        else{
            stop = true;
        } 
    }
    

    cout<<ans;


}