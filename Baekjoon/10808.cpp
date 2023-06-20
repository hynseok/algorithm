#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    int alpha[26]={0,};
    string S;
    cin>>S;

    for(int i=0;i<S.size();i++)
    {
        int temp;
        temp = S[i] - 'a';
        alpha[temp]++;
    }
    for(int i=0;i<26;i++)
    {
        cout<<alpha[i]<<' ';
    }
    return 0;
}