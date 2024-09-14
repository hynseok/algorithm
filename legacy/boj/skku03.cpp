#include <bits/stdc++.h>
using namespace std;
bool isPrime[5000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0;i<=N;i++){
        isPrime[i] = true;
    }
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            for(int j=i*2;j<=N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    int i = N/2;
    int ansN=20;
    while(ansN--){
        while(!isPrime[i]) i--;
        cout<<'?'<<' '<<i;
        cout<<flush;
        int ans;
        cin>>ans;
        if(ans==1){
            i++;
            while(!isPrime[i])i++;
        }
        else if(ans==0){
            cout<<'!'<<' '<<i;
            cout<<flush;
            return 0;
        }
    }
    return 0;
}