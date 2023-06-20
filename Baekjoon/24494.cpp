#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string A, B, temp;
    char C;
    int visited[9] = {0, };
    int visited2[9] = {0, };
    int G=0, Y=0;
    for(int i=0;i<3;i++){
        cin>>temp;
        A+=temp;
    }
    for(int i=0;i<3;i++){
        cin>>temp;
        B+=temp;
    }
    
    for(int i=0;i<9;i++){
        C = B[i];
        for(int j=0;j<9;j++){
            if(visited[j]==1) continue;
            if(A[j] == C && i==j){
                G++;
                visited[j] = 1;
                visited2[i] = 1;
                break;
            }
        }
    }
    for(int i=0;i<9;i++){
        C = B[i];
        if(visited2[i]==1) continue;
        for(int j=0;j<9;j++){
            if(visited[j]==1) continue;
            if(A[j] == C){
                Y++;
                visited[j] = 1;
                visited2[i] = 1;
                break;
            }
        }
    }
    cout<<G<<'\n'<<Y<<'\n';
    return 0;
}