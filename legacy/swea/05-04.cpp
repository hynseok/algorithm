#include <bits/stdc++.h>
using namespace std;

int N;
double W;
long long result;
long long parent[1001];

struct Node{
    long long y;
    long long x;
};
Node arr[1001];

struct Dis{
    long long start;
    unsigned long long end;
    double cost;

    bool operator<(const Dis& d)
    const{
        return cost>d.cost;
    }
};

long long findparent(long long num){
    if(num==parent[num]){
        return num;
    }
    return num = findparent(parent[num]);
}

void merge(long long a, long long b){
    long long x = findparent(a);
    long long y = findparent(b);
    parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout<<fixed;
    cout.precision(0);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;

        long long x;
        for(int i=0;i<N;i++){
            cin>>arr[i].x;
            parent[i] = i;    
        }
        long long y;
        for(int i=0;i<N;i++) cin>>arr[i].y;
        cin>>W;

        priority_queue<Dis> pq;

        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                double cost = sqrt(pow(abs(arr[i].x-arr[j].x),2)+pow(abs(arr[i].y-arr[j].y),2));
                Dis temp;
                temp.start = i; temp.end = j;
                temp.cost = cost;
                pq.push(temp);
            }
        }

        double result = 0;

        while(!pq.empty()){
            if(findparent(pq.top().start)!=findparent(pq.top().end)){
                merge(pq.top().start,pq.top().end);
                result += W * pow(pq.top().cost,2);
            }
            pq.pop();
        }

        cout<<'#'<<tc<<' '<<result<<'\n';
    
    }
    return 0;
}