#include <bits/stdc++.h>
using namespace std;
int T, L, N;

struct P{
    int start;
    int end;
    int sum;
};

vector<P> List;

P Find(int inp){
    int start = 0; int end = N-1;
    while(end>start){
        int mid = (start + end) / 2;
        if(List[mid].end>=inp) end = mid;
        else start = mid + 1;
    }
    return List[end];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        List.clear();
        cin>>L>>N;
        int s = 0;
        for(int i=0;i<N;i++){
            int t1, t2;
            cin>>t1>>t2;
            P temp;
            temp.start = t1; temp.end = t2;
            s += (t2 - t1);
            temp.sum = s;
            List.push_back(temp);
        }
        int ans = -1;
        for(int i=0;i<N;i++){
            int sum = 0;
            int start = List[i].start; int end = start + L;
            P prev = Find(end);
            sum = prev.sum - List[i].sum + List[i].end - List[i].start;

            if(prev.end > end && prev.start < end){
                sum -= prev.end - end;
            }
            else if(prev.end>end){
                sum -= prev.end - prev.start;
            }
            ans = max(ans,sum);
        }
        cout<<'#'<<tc<<' '<<ans<<'\n';
    }
    
    return 0;
}