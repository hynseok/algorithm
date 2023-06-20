#include <bits/stdc++.h>
using namespace std;

int T;
int N, QueryN;
int arr[100001];
vector<int> minTree;
vector<int> maxTree;

int init(int node, int start, int end, bool T){
    if(start==end){
        if(T==false){
            return minTree[node] = arr[start];
        }
        else{
            return maxTree[node] = arr[start];
        }
    }
    int mid = (start+end) / 2;
    int leftR = init(node*2, start, mid, T);
    int rightR = init(node*2+1,mid+1,end,T);

    if(T==false){
        minTree[node] = min(leftR,rightR);
        return minTree[node];
    }
    else{
        maxTree[node] = max(leftR,rightR);
        return maxTree[node];
    }
}

void update(int node, int start, int end, int index, int val, bool T){
    if (index < start || index > end) { return; }

    if(start==end){
        if(T==false){
            arr[index] = val;
            minTree[node] = val; 
            return; 
        }
        else{
            arr[index] = val;
            maxTree[node] = val;
            return;
        }
    }
    int mid = (start+end) / 2;
    update(node*2, start, mid, index, val, T);
    update(node*2+1, mid+1, end, index, val, T);
    
    if(T==false){
        minTree[node] = min(minTree[node*2],minTree[node*2+1]);
    }
    else{
        maxTree[node] = max(maxTree[node*2],maxTree[node*2+1]);
    }
}


int Query(int node, int start, int end, int left, int right, bool T){
    if(left>end||right<start){
        if(T==false) return 2e9;
        else return -2e9;
    }
    if(left<=start&&end<=right){
        if(T==false) return minTree[node];
        else return maxTree[node];
    }

    int mid = (start+end) / 2;
    int leftR = Query(node*2, start, mid, left, right, T);
    int rightR = Query(node*2+1,mid+1,end,left,right,T);

    if(T==false) return min(leftR,rightR);
    else return max(leftR,rightR);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"#"<<tc<<' ';
        cin>>N>>QueryN;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        int H = (int)ceil(log2(N));
        minTree = vector<int>(1<<(H+1));
        maxTree = vector<int>(1<<(H+1));

        init(1,0,N-1,false);
        init(1,0,N-1,true);

        for(int i=0;i<QueryN;i++){
            int t, a, b;
            cin>>t>>a>>b;

            if(t==0){
                update(1,0,N-1,a,b,true);
                update(1,0,N-1,a,b,false);
            }
            else if(t==1){
                cout<<Query(1,0,N-1,a,b-1,true)-Query(1,0,N-1,a,b-1,false)<<' ';
            }
        }
        cout<<'\n';

    }
    
    return 0;
}