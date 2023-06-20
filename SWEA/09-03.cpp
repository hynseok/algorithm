#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[1000001];
int temp[1000001];
int T, N;

ll Merge(int left, int mid, int right){
    int i=left, j=mid+1, k=left, l;
    ll inCnt = 0;
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            inCnt += (ll)(mid-i+1);
            temp[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(l=j;l<=right;l++,k++){
            temp[k] = arr[l];
        }
    }
    else{
        for(l=i;l<=mid;l++,k++){
            temp[k] = arr[l];
        }
    }
    for(int l=left;l<=right;l++){
        arr[l] = temp[l];
    }
    return inCnt;
}

ll FindInversion(int left, int right){
    ll ret = 0;
    if(left<right){
        int mid = (left+right)/2;
        ret += FindInversion(left,mid);
        ret += FindInversion(mid+1,right);
        ret += Merge(left,mid,right);
    }
    return ret;
}  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        memset(arr,0,sizeof(arr));
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        
        cout<<'#'<<tc<<' '<<FindInversion(0,N-1)<<'\n';
    }
    return 0;
}