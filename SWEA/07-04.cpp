#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        priority_queue<int,vector<int>,greater<int>> minQ; //bigger 값을 넣음
        priority_queue<int,vector<int>,less<int>> maxQ;
        int mid_val;
        int input[2];
        unsigned long long sum = 0;
        cin>>N>>mid_val;
        for(int i=0;i<N;i++){
            cin>>input[0]>>input[1];
            int bigger = 0;
            for(int j=0;j<2;j++){
                if(input[j]>mid_val){
                    bigger++;
                    minQ.push(input[j]);
                }
                else
                {
                    maxQ.push(input[j]);
                }
            }

            if(bigger==2){
                int temp = minQ.top();
                minQ.pop();
                maxQ.push(mid_val);
                mid_val = temp;
            }
            else if(bigger==0){
                int temp = maxQ.top();
                maxQ.pop();
                minQ.push(mid_val);
                mid_val = temp;
            }
            sum += mid_val;
            if(sum>=20171109) sum%= 20171109;
            
        }
        
        cout<<'#'<<tc<<' '<<sum<<'\n';

    }

    return 0;
}