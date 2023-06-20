#include <bits/stdc++.h>
using namespace std;

int N;
int Map[13][13];
int coreN;
int ans;
int ansarr[13];
void dfs(int count, int connect, vector<pair<int,int> > v){
    
    if(count==coreN){
        int line = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Map[i][j]==2) line++;
            }
        }
        ansarr[connect] = min(ansarr[connect],line);
        return;
    }

    int cy = v[count].first;
    int cx = v[count].second;
    
    int flag = 1;
    for(int i=0;i<cy;i++){
        if(Map[i][cx]!=0){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(int i=0;i<cy;i++) Map[i][cx] = 2;
        dfs(count+1,connect+1,v);
        for(int i=0;i<cy;i++) Map[i][cx] = 0;
    }

    flag = 1;
    for(int i=cy+1;i<N;i++){
        if(Map[i][cx]!=0){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(int i=cy+1;i<N;i++) Map[i][cx] = 2;
        dfs(count+1,connect+1,v);
        for(int i=cy+1;i<N;i++) Map[i][cx] = 0;
    }

    flag = 1;
    for(int i=0;i<cx;i++){
        if(Map[cy][i]!=0){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(int i=0;i<cx;i++) Map[cy][i] = 2;
        dfs(count+1,connect+1,v);
        for(int i=0;i<cx;i++) Map[cy][i] = 0;
    }

    flag = 1;
    for(int i=cx+1;i<N;i++){
        if(Map[cy][i]!=0){
            flag = 0;
            break;
        }
    }
    if(flag){
            for(int i=cx+1;i<N;i++) Map[cy][i] = 2;
            dfs(count+1,connect+1,v);
            for(int i=cx+1;i<N;i++) Map[cy][i] = 0;
    }

    dfs(count+1,connect,v);

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        coreN = 0;
        memset(Map,0,sizeof(Map));
        fill(ansarr,ansarr+13,9999);
        
        cin>>N;
        vector<pair<int,int> > idx;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>Map[i][j];
                if(Map[i][j]==1){
                    if(i==0||j==0||i==N-1||j==N-1) continue;
                    idx.push_back(make_pair(i,j));
                    coreN++;
                }

            }
        }

        dfs(0,0,idx);

        for(int i=coreN;i>0;i--){
            if(ansarr[i]!=9999){
                ans = ansarr[i];
                break;
            }
        }

        cout<<'#'<<tc<<' '<<ans<<'\n';

    }
    return 0;
}