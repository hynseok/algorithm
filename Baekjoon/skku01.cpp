#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool flag = false;
    int N, M, K;
    cin>>N>>M>>K;

    int max = N+M-1;
    if(max<=K) flag = true;
    
    if(flag){
        cout<<"YES"<<'\n';
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                cout<<i+j<<' ';
            }
            cout<<'\n';
        }
    }
    else{
        cout<<"NO"<<'\n';
    }

    return 0;
}