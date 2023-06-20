#include <bits/stdc++.h>
using namespace std;

int Map[1504][1504];
bool visited[1504][1504];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
pair<int,int> swan;
queue<pair<int,int>> SQ, SNQ, WQ, WNQ;
int R, C;
int flag = 0;

void melt(){
    while(!WQ.empty()){
        int y = WQ.front().first;
        int x = WQ.front().second;
        WQ.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx>=0&&nx<C&&ny>=0&&ny<R){
                if(Map[ny][nx]==1){
                    Map[ny][nx] = 0;
                    WNQ.push({ny,nx});
                }
            }
        }
    }

}

void go(){
    while(!SQ.empty()&&flag==0){
        int y = SQ.front().first;
        int x = SQ.front().second;
        SQ.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny>=0&&ny<R&&nx>=0&&nx<C){
                if(!visited[ny][nx]){
                    if(Map[ny][nx]==0){
                        visited[ny][nx]=true;
                        SQ.push({ny,nx});
                    }
                    else if(Map[ny][nx]==1){
                        visited[ny][nx] = true;
                        SNQ.push({ny, nx});
                    }
                    else if(Map[ny][nx]==2){
                        visited[ny][nx] = true;
                        flag = 1;
                        break;
                    }

                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int by, bx;
    string temp;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>temp;
        for(int j=0;j<C;j++){
            if(temp[j]=='.'){
                Map[i][j] = 0;
                WQ.push({i,j});
            }
            else if(temp[j]=='X')Map[i][j]=1;
            else if(temp[j]=='L'){
                Map[i][j]=2;
                WQ.push({i,j});
                swan.first = i; swan.second = j;
            }
        }
    }

    int Day = 0;
    SQ.push({swan.first,swan.second});
    visited[swan.first][swan.second] = true;
    while(flag==0){
        go();
        if(flag==0){
            melt();
            WQ = WNQ;
            SQ = SNQ;
            while(!WNQ.empty()) WNQ.pop();
            while(!SNQ.empty()) SNQ.pop();
            Day++;
        }
    }  
    cout<<Day<<'\n';
    return 0;
}