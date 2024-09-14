#include <bits/stdc++.h>
using namespace std;
#define HASH_SIZE (1<<30)
#define DIV (HASH_SIZE-1) 
typedef unsigned long long ull;
int T, H, W, N, M;
int Map[2001][2001];
int Tmap[2001][2001];
int Thash[2001][2001];
int temp[2001][2001];

int GetMul(int num, int shift){
    ull rev = 1;
    for(int i=0;i<num-1;i++){
        rev = (rev<<shift) + rev;
    }
    return (int)(rev&DIV);
}

int GetHash(int* piv, int num, int shift){
    ull hash = 0;
    for(int i=0;i<num;i++){
        hash = (hash<<shift) + hash + *piv++;
    }
    return (int)(hash&DIV);
}

int NextHash(int prev, int sub, int mul, int add, int shift){
    ull hash = prev - (sub*mul);
    hash = (hash<<shift) + hash + add;
    return (int)(hash&DIV);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int tc=1;tc<=T;tc++){
        int ans = 0;

        cin>>H>>W>>N>>M;
        for(int i=0;i<H;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<W;j++){
                if(temp[j]=='o')Map[i][j]=1;
                else Map[i][j]=0;
            }
        }
        for(int i=0;i<N;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<M;j++){
                if(temp[j]=='o')Tmap[i][j]=1;
                else Tmap[i][j]=0;
            }
        }
        
        for(int i=0;i<H;i++)temp[0][i] = GetHash(Map[i],W,4);
        int Hash = GetHash(temp[0],H,5);

        int mulC = GetMul(W,4);
        int mulR = GetMul(H,5);
        for(int i=0;i<N;i++){
            temp[0][i] = GetHash(Tmap[i],W,4);
            for(int j=1;j<M-W+1;j++){
                temp[j][i] = NextHash(temp[j-1][i],Tmap[i][j-1],mulC,Tmap[i][j+W-1],4);
            }
        }
        for(int i=0;i<M-W+1;i++){
            Thash[0][i] = GetHash(temp[i],H,5);
            for(int j=1;j<N-H+1;j++){
                Thash[j][i] = NextHash(Thash[j-1][i],temp[i][j-1],mulR,temp[i][j+H-1],5);
            }
        }

        for(int i=0;i<N-H+1;i++){
            for(int j=0;j<M-W+1;j++){
                if(Thash[i][j]==Hash) ans++;
            }
        }
        cout<<'#'<<tc<<' '<<ans<<'\n';
    }
    
    return 0;
}