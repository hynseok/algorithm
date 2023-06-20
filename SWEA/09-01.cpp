#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<string> V;

bool compare(string A, string B){
    if(A.length()==B.length()){
        return A<B;
    }
    return A.length()<B.length();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        V.clear();
        cin>>N;
        string temp;
        for(int i=0;i<N;i++){
            cin>>temp;
            V.push_back(temp);
        }

        sort(V.begin(),V.end(),compare);
        V.erase(unique(V.begin(),V.end()),V.end());
        
        cout<<'#'<<tc<<'\n';
        for(int i=0;i<V.size();i++){
            cout<<V[i]<<'\n';
        }

    }

    
    return 0;
}