#include <bits/stdc++.h>
using namespace std;

int N;
int visited[21] = {0, };
int Map[21][21] = {0, };
int ans = 987654321;

void DFS(int x, int cnt){
    if(cnt==N/2){
        int start, link;
        start = 0;
        link = 0;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(visited[i]==1&&visited[j]==1) start += Map[i][j];
                if(visited[i]==0&&visited[j]==0) link += Map[i][j];
            }
        }
        int temp = abs(start-link);
        if(ans>temp) ans = temp;

        return;
    }

    for(int i=x;i<N;i++)
    {
        visited[i] = 1;
        DFS(i+1, cnt+1);
        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>Map[i][j];
        }
    }

    DFS(1,0);

    cout<<ans;

    return 0;
}