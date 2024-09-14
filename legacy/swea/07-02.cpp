#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<'#'<<tc<<' ';
        int N, cmd, data;
        cin>>N;
        priority_queue<int> pq;
        for(int i=0;i<N;i++){
            cin>>cmd;
            if(cmd==1){
                cin>>data;
                pq.push(data);
            }
            else if(cmd==2){
                if(pq.empty()) cout<<-1<<' ';
                else{
                    cout<<pq.top()<<' ';
                    pq.pop();
                }
            }
        }
        cout<<'\n';
    }

    return 0;
}