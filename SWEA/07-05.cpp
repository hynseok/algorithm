#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int NumArr[11];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>NumArr[i];
        }
        cin>>K;
        pq.push({0,K});
        while(pq.top().second){
            pair<int,int> curr = pq.top();
            pq.pop();
            pq.push({curr.first+curr.second,0});
            for(int i=0;i<N;i++){
                pq.push({curr.first+curr.second%NumArr[i],curr.second/NumArr[i]});
            }
        }
        cout<<'#'<<tc<<' '<<pq.top().first<<'\n';
    }
    return 0;
}