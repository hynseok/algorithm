#include <bits/stdc++.h>
using namespace std;

int N, length;
string blocks[4]; // block size = 6
string words[10];
bool flag;

void swap(char &a,char &b){
    char temp = a;
    a = b;
    b = temp;
}

void checkPermutation(string S, int cnt, int tc){
    if(cnt==length){
        string temp = "";
        for(int i=0;i<length;i++) temp += S[i];
        if(temp == words[tc]){
            flag = true;
        }
    }
    for(int i=cnt;i<4;i++){
        swap(S[cnt],S[i]);
        checkPermutation(S,cnt+1,tc);
        swap(S[cnt],S[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0;i<4;i++){
        cin>>blocks[i];
    }
    for(int i=0;i<N;i++){
        cin>>words[i];
    }

    for(int tc=0;tc<N;tc++){
        flag = false;
        length = words[tc].length();
        for(int i=0;i<6;i++){
            if(flag==true)break;
           for(int j=0;j<6;j++){
                if(flag==true)break;
                for(int k=0;k<6;k++){
                    if(flag==true)break;
                    for(int l=0;l<6;l++){
                        if(flag==true)break;
                        string temp = "";
                        temp += blocks[0][i];
                        temp += blocks[1][j];
                        temp += blocks[2][k];
                        temp += blocks[3][l];
                        checkPermutation(temp,0,tc);
                    }
                }
            }
        }
        if(flag==true)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}