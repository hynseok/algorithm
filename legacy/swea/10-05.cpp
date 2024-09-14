#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int c1, c2;
vector<int> cow;
vector<int> hrs;

int binarySearch(int key){
    int left = 0;
    int right = hrs.size()-1;
    int mid = (left + right) / 2;

    if(key<hrs[left]) return 0;
    if(hrs[right]<key) return hrs.size() - 1;
    while(left<=right){
        mid = (left + right) / 2;
        if(hrs[mid]==key) return mid;
        else if(hrs[mid]<key) left = mid + 1;
        else right = mid - 1;
    } 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cow.clear();
        hrs.clear();

        cin>>N>>M;
        cin>>c1>>c2;
        int temp;
        for(int i=0;i<N;i++){
            cin>>temp;
            cow.push_back(temp);
        }
        for(int i=0;i<M;i++){
            cin>>temp;
            hrs.push_back(temp);
        }
        sort(hrs.begin(),hrs.end());

        int ans = 0;
        int min = 987654321;
        for(int i=0;i<N;i++){
            int idx = binarySearch(cow[i]);
            int tidx1 = idx-1;
            int tidx2 = idx+1;

            if(abs(cow[i]-hrs[idx])<min) {
                ans = 1;
                min = abs(cow[i]-hrs[idx]);
            } 
            else if(abs(cow[i]-hrs[idx])==min) ans++;

            if(tidx1>=0) {
                if(abs(cow[i]-hrs[tidx1])<min) {
                    ans = 1;
                    min = abs(cow[i]-hrs[tidx1]);
                } 
                else if(abs(cow[i]-hrs[tidx1])==min) ans++;
            }
            if(tidx2<N) {
                if(abs(cow[i]-hrs[tidx2])<min) {
                    ans = 1;
                    min = abs(cow[i]-hrs[tidx2]);
                } 
                else if(abs(cow[i]-hrs[tidx2])==min) ans++;
            }
        }

        cout<<'#'<<tc<<' '<<min+abs(c1-c2)<<' '<<ans<<'\n';
    }

    return 0;
}