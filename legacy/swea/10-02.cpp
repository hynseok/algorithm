#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int T;
ull N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;
        N *= 2;
        ull K = sqrt(N);
        
        if(K*(K+1)==N){
            cout<<'#'<<tc<<' '<<K<<'\n';
        }
        else{
            cout<<'#'<<tc<<' '<<-1<<'\n';
        }

    }
    
    return 0;
}