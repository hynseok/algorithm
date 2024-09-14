#include <bits/stdc++.h>
using namespace std;
#define MAX 17
#define INF 987654321

int N;
int dist[MAX][MAX];
bool visited[MAX] = {0, };
vector<int> path;

int shortestPath(vector<int>& path, int currentLength)
{
    if(path.size()==N)
    {
        return currentLength + dist[path[0]][path.back()];
    }

    int ret = INF;
    for(int next=1;next<=N;next++)
    {
        if(visited[next])continue;
        int now = path.back();
        path.push_back(next);
        visited[next] = true;
        int cand = shortestPath(path, currentLength+dist[now][next]);
        ret = min(cand,ret);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>dist[i][j];
        }
    }

    cout<<shortestPath(path, 0);
}
