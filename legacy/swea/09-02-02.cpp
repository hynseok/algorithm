#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull T, A, B, K;

ull pow(unsigned long long n, unsigned long long sum){
    if(n==0){
        return 1;
    }

    ull result = pow(n/2,sum);
    result = (result*result)%sum;
    if(n&1){
        result = (result*2)%sum;
    }
    return result;
}
ull find(ull A, ull B, ull K){
    ull sum = A+B;
    ull GT = (pow(K,sum)*A)%sum;
    return min(GT,sum-GT); 
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>A>>B>>K;  
        
        cout<<'#'<<tc<<' '<<find(A,B,K)<<'\n';
    }

    return 0;
}