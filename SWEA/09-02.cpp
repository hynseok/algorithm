#include <bits/stdc++.h>
using namespace std;

int T, A, B, K;

int FindCicle(int A, int B){
    int X, Y;
    int ret = 0;
    if(A==B) {
        return -1;
    }
    else{
        X=min(A,B); Y=max(A,B);
    }

    Y-=X;
    X+=X;
    ret++;
    while(X!=A&&X!=B){
        if(X<Y){
            Y-=X;
            X+=X;
            ret++;
        }
        else{
            X-=Y;
            Y+=Y;
            ret++;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>A>>B>>K;  
        int cicle = FindCicle(A,B);
        if(cicle==-1){
            cout<<'#'<<tc<<' '<<0<<'\n';
            continue;
        }
        int N = K%cicle;
        for(int i=0;i<N;i++){
            if(A<B){
                B-=A;
                A+=A;
            }
            else{
                A-=B;
                B+=B;
            }
        }
        cout<<'#'<<tc<<' '<<min(A,B)<<'\n';
    
    }

    return 0;
}