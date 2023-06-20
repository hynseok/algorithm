#include <bits/stdc++.h>
using namespace std;

int ans=987654321, N;
int combi3[6][3] = {{9,3,1},{9,1,3},{3,9,1},{1,9,3},{3,1,9},{1,3,9}};
int visited[64][64][64];
int scv[3];
struct A{
    int a, b, c;
};

int bfs(int a, int b, int c)
{
    queue<A> Q;
    visited[a][b][c] = 1;
    A temp; temp.a = a; temp.b = b; temp.c = c;
    Q.push(temp);

    while(!Q.empty())
    {
        int a = Q.front().a;
        int b = Q.front().b;
        int c = Q.front().c;
        Q.pop();

        if(visited[0][0][0]) break;
        for(int i=0;i<6;i++)
        {
            int na = max(0,a-combi3[i][0]);
            int nb = max(0,b-combi3[i][1]);
            int nc = max(0,c-combi3[i][2]);
            if(visited[na][nb][nc])continue;
            visited[na][nb][nc] = visited[a][b][c] +1;
            A temp; temp.a = na; temp.b = nb; temp.c = nc;
            Q.push({na,nb,nc});
        }
    }    
    return visited[0][0][0] - 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) cin>>scv[i];
    cout<<bfs(scv[0],scv[1],scv[2])<<'\n';
    return 0;
}