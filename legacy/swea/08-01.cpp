#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string,int> Hashmap;
    int T;
    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        Hashmap.clear();
        int cnt = 0;
        int N, M;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            string temp;
            cin>>temp;
            Hashmap[temp] = i;
        }
        for(int i=0;i<M;i++){
            string temp;
            cin>>temp;
            if(Hashmap.find(temp)!=Hashmap.end()) cnt++;
        }
        cout<<'#'<<tc<<' '<<cnt<<'\n';

    }

    return 0;
}