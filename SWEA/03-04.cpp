#include <bits/stdc++.h>
using namespace std;

int T, N, M, L;
int orderN, buf;
int idx, temp;
char order;
list<int> li;
list<int>::iterator iter;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int i=1;i<=T;i++){
        li.clear();

        cin>>N>>M>>L;
        for(int j=0;j<N;j++){
            cin>>buf;
            li.push_back(buf);
        }
        for(int j=0;j<M;j++){
            cin>>order;
            if(order=='I'){
                cin>>idx>>temp;
                iter = li.begin();
                for(int k=0;k<idx;k++)iter++;
                li.insert(iter,temp);
            }
            else if(order=='D'){
                cin>>idx;
                iter = li.begin();
                for(int k=0;k<idx;k++)iter++;
                li.erase(iter);
            }
            else if(order=='C'){
                cin>>idx>>temp;
                iter = li.begin();
                for(int k=0;k<idx;k++)iter++;
                li.erase(iter++);
                li.insert(iter,temp);
            }
        }

        if(L>li.size()){
            cout<<"#"<<i<<' '<<-1<<'\n';
            continue;
        }

        iter = li.begin();
        for(int j=0;j<L;j++)iter++;
        cout<<"#"<<i<<' '<<(*iter)<<'\n';
    }
    return 0;
}