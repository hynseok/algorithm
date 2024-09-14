//라빈카프알고리즘, KMP알고리즘
#include <bits/stdc++.h>
#define d 256
#define MOD 100003
using namespace std;
int cnt = 0;

void FindString(string B, string S){
    int Bsize = B.size();
    int Ssize = S.size();

    long long Bhash = 0;
    long long Shash = 0;
    long long power = 1;

    for(int i=0;i<Ssize-1;i++){
        power = (power*d)%MOD;
    }

    for(int i=0;i<Ssize;i++){
        Bhash = (d*Bhash+B[i]) % MOD;
        Shash = (d*Shash+S[i]) % MOD;
    }

    for(int i=0;i<=Bsize-Ssize;i++){
        if(Bhash==Shash){
            /*if(B.substr(i,Ssize)==S)*/ cnt++;
        }
        if(i+Ssize<Bsize){
            Bhash = Bhash - (B[i]*power) % MOD;
            Bhash = (Bhash + MOD) %MOD;
            Bhash = ((Bhash*d)%MOD + B[i+Ssize]) % MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cnt = 0;
        string B, S;
        cin>>B>>S;

        FindString(B,S);

        cout<<'#'<<tc<<' '<<cnt<<'\n';
    }
    
    return 0;
}