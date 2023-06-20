#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int N, M, flag=0;
        cin>>N>>M;

        for(int j=0;j<N;j++){
            if(M&(1<<j))continue;
            else{
                flag = 1;
                break;
            }
        }

        if(flag) cout<<'#'<<i<<' '<<"OFF"<<'\n';
        else cout<<'#'<<i<<' '<<"ON"<<'\n';
    }

    return 0;
}