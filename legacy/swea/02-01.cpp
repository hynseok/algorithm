#include <bits/stdc++.h>
using namespace std;

int visited[10] = {0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, N, Num, flag;
    string sNum;
    
    cin>>T;
    for(int t=1;t<=T;t++){
        Num = 0; flag = 0;
        memset(visited,0,sizeof(visited));
        cin>>N;
    
        while(flag!=1023){
            Num+=N;
            sNum = to_string(Num);
            for(int i=0;i<sNum.size();i++){
                int idx = sNum[i] - '0';
                if(visited[idx]==0){
                    visited[idx]=1;
                    flag+=(1<<idx);
                }
            }
        }
        cout<<'#'<<t<<' '<<Num<<'\n';
    }

    return 0;
}