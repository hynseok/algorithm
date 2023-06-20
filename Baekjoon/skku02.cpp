#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<string> V;
    string S;
    string buffer = "";
    getline(cin, S,'\n');
    for(int i=0;i<S.size();i++){
        if(S[i]=='<'||S[i]=='>'||S[i]=='('||S[i]==')'||S[i]==' '){
            if(buffer!="")V.push_back(buffer);
            buffer = "";
            buffer += S[i];
            V.push_back(buffer);
            buffer = "";
        }
        else if(S[i]=='&'||S[i]=='|'){
            if(buffer!="")V.push_back(buffer);
            buffer = "";
            buffer += S[i];
            i++; buffer += S[i];
            V.push_back(buffer);
            buffer = "";
        }
        else{
            buffer += S[i];
        }
    }
    if(buffer!="")V.push_back(buffer);

    string ans = "";
    for(int i=0;i<V.size();i++){
        if(V[i]==" "||V[i]=="")continue;
        if(ans=="")ans+=V[i];
        else{
            ans+=" ";
            ans+=V[i];
        }
    }
    cout<<ans;
    return 0;
}