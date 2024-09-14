#include <bits/stdc++.h>
using namespace std;

int N;
int buf;
int orderN; char order;
list<int> li;
list<int>::iterator iter;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1;i<=10;i++){
        li.clear();
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>buf;
            li.push_back(buf);
        }
        cin>>orderN;
        for(int j=0;j<orderN;j++){
            cin>>order;
            int idx, size, temp;
            if(order=='I'){
                cin>>idx>>size;
                iter = li.begin();
                list<int> Tli;

                for(int k=0;k<idx;k++)iter++;
                for(int k=0;k<size;k++){
                    cin>>temp;
                    Tli.push_back(temp);
                }
                li.splice(iter,Tli);
                
            }
            else if(order=='D'){
                cin>>idx>>size;
                iter = li.begin();
                for(int k=0;k<idx;k++) iter++;
                for(int k=0;k<size;k++) iter = li.erase(iter);
            }
            else if(order=='A'){
                cin>>size;
                for(int k=0;k<size;k++){
                    cin>>temp;
                    li.push_back(temp);
                }
            }
        }

        cout<<'#'<<i;
        iter = li.begin();
        for(int j=0;j<10;j++){
            cout<<' '<<*(iter++);
        }cout<<'\n';

    }
    return 0;
}