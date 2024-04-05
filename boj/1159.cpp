#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    int N;
    string S;
    int alpha[26] = {0,};
    vector<char> v;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>S;
        int idx;
        idx = S[0] - 'a';
        alpha[idx]++;
    }
    for(int i=0;i<26;i++)
    {
        if(alpha[i]>=5)
        {
            char alphabet;
            alphabet = 'a' + i;
            v.push_back(alphabet);
        }
    }
    if(v.empty()) cout<<"PREDAJA";
    else
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
    }

    return 0;
}