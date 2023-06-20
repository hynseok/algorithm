#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    int tok = 1;
    string S;
    cin>>S;
    int length = S.length();
    for(int i=0;i<length/2;i++)
    {
        if(S[i]==S[length-1-i]) continue;
        tok = 0;
        break;
    }
    cout<<tok;
    return 0;
}