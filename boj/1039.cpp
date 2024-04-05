#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ans, K, M;
    int level = 0;
    int max = 0;
    string N; 

    cin >> N >> K;
    M = N.length();
    
    if(M==1 || (M==2 && N[1] == '0')){
      cout << "-1";
      return 0;
    }

    queue<string> Q;
    Q.push(N);

    while(!Q.empty() && level < K){
      set<string> visited;
      int qs = Q.size();
      for(int q=0; q<qs; q++){
        string curr = Q.front();
        Q.pop();

        for(int i=0; i<M-1; i++){
          for(int j=i+1; j<M; j++){
            if(i==0 && curr[j]=='0') continue;

            swap(curr[i],curr[j]);
            if(visited.find(curr) == visited.end()){
              if(level == K-1 && max < stoi(curr)){
                max = stoi(curr);
              }
              Q.push(curr);
              visited.insert(curr);
            }
            swap(curr[i],curr[j]);
          }
        }
      }
      level++;
    }
    if(level != K) cout << "-1";
    else cout << max;

    return 0;
}