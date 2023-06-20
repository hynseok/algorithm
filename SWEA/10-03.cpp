#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int T, N;
ull M;
ull List[101];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        ull left = 1;
        ull right = 0;
        ull mid;
        ull cnt = 0;

        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>List[i];
            right = max(right, List[i]);
        }

        while(left<=right){
            mid = (left + right) / 2;
            cnt = 0;
            for(int i=0;i<N;i++){
                cnt+=List[i]/mid;
            }
            if(cnt<M) right = mid - 1;
            else left = mid + 1;
        }

        cout<<'#'<<tc<<' '<<right<<'\n';
     
    }
    
    return 0;
}