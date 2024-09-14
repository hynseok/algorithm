#include <bits/stdc++.h>
using namespace std;
int T;
string S;
vector<string> suffixArr;
int LCP[401];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        suffixArr.clear();
        memset(LCP,0,sizeof(LCP));
        int K; cin>>K;
        cin>>S;
        
        for(int i=0;i<S.size();i++){
            suffixArr.push_back(S.substr(i));
        }

        sort(suffixArr.begin(),suffixArr.end());
        LCP[0] = 0;
        for(int i=1;i<S.size();i++){
            string prev = suffixArr[i-1];
            string curr = suffixArr[i];
            int num = 0;
            while(num<prev.size()&&num<curr.size()&&prev[num]==curr[num]){
                num++;
            }
            LCP[i] = num;
        }

        int cnt = 0;
        for(int i=0;i<S.length();i++){
            cnt += suffixArr[i].size() - LCP[i];
            if(cnt>=K){
                cout<<'#'<<tc<<' '<<suffixArr[i].substr(0,suffixArr[i].size()-(cnt-K))<<'\n';
                break;
            }
        }
        if(cnt<K)cout<<'#'<<tc<<' '<<"none"<<'\n';

    }
    
    return 0;
}