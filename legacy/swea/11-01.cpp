#include <bits/stdc++.h>
using namespace std;

int T;
string S;
vector<string> parr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        parr.clear();
        int idx;
        cin>>idx;
        cin>>S;
        for(int i=0;i<S.length();i++){
            parr.push_back(S.substr(i));
        }    
        sort(parr.begin(),parr.end());
        cout<<'#'<<tc<<' '<<parr[idx-1]<<'\n';
    }

    return 0;
}