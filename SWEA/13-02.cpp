#include <bits/stdc++.h>
using namespace std;

int T;
int N, QueryN;
long long arr[100001];
vector<long long> Tree;

void init(int node, int start, int end){
    if(start==end){
        Tree[node] = arr[start];
    }
    else{
        int mid = (start+end) / 2;
        init(node*2,start,mid);
        init(node*2+1,mid+1,end);
        Tree[node] = Tree[node*2] + Tree[node*2+1];
    }
}

void update(int node, int start, int end, int index, long long val){
    if (index < start || index > end) { return; }
    if(start==end){
        arr[index] = val;
        Tree[node] = val;
        return;
    }
    int mid = (start+end) / 2;
    update(node*2, start , mid, index, val);
    update(node*2+1, mid+1, end, index, val);
    Tree[node] = Tree[node*2] + Tree[node*2+1];   
}


long long Query(int node, int start, int end, int left, int right){
    if(left>end||right<start){
        return 0;
    }
    if(left<=start&&end<=right){
        return Tree[node];
    }
    int mid = (start+end) / 2;
    long long leftR = Query(node*2,start,mid,left,right);
    long long rightR = Query(node*2+1,mid+1,end,left,right);
    return leftR + rightR;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"#"<<tc<<' ';
        cin>>N>>QueryN;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<N;i++){
            int temp;
            cin>>temp;
            if(i%2==0){
                arr[i] = temp;
            }
            else{
                arr[i] = -temp;
            }
        }

        int H = (int)ceil(log2(N));
        Tree = vector<long long>(1<<(H+1));
        init(1,0,N-1);

        for(int i=0;i<QueryN;i++){
            int t, a, b;
            cin>>t>>a>>b;

            if(t==0){
                if(a%2==0){
                    update(1,0,N-1,a,b);
                }
                else{
                    update(1,0,N-1,a,-b);
                }
            }
            else if(t==1){
                if(a%2==0){
                    cout<<Query(1,0,N-1,a,b-1)<<' ';
                }
                else{
                    cout<<-Query(1,0,N-1,a,b-1)<<' ';
                }
            }
        }
        cout<<'\n';

    }
    
    return 0;
}