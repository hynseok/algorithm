#include <bits/stdc++.h>
using namespace std;

int N;
int Map[21][21];
int visited[21][21]={0,};
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int ans = 0;
struct Shark
{
    int x;
    int y;
    int size;
    int eat;
    int d;
};

Shark start;

bool check(int size)
{
    int chk=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(size>Map[i][j]&&Map[i][j]>0) chk++;
        }
    }
    if(chk==0) return false;
    else return true;
}

void bfs()
{
    queue<Shark> Q;
    Q.push(start);
    visited[start.y][start.x] = 1;
    if(!check(start.size)) return;

    while(!Q.empty())
    {
        Shark temp;
        temp = Q.front();
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
                    if(temp.size>Map[nextY][nextX]&&Map[nextY][nextX]>0)
                    {
                        Map[nextY][nextX] = 0;
                        next.eat++;
                        if(next.eat==next.size)
                        {
                            next.size++;
                            next.eat = 0;
                        }
                        ans += next.d;
                        next.d = 0;
                        if(!check(next.size)) return;
                        for(int i=0;i<21;i++){ memset(visited[i],0,sizeof(int)*21); }
                        while(!Q.empty()) Q.pop();
                    }
                    visited[next.y][next.x] = 1;
                    Q.push(next);
                    
                }
            }
        }
    }
}

void input()
{
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
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    bfs();

    cout<<ans;


}