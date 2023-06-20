#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    map<string,string> password;

    int N, M;
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        string tst1, tst2;
        cin>>tst1>>tst2;
        password[tst1]=tst2;
    }

    for(int i=0;i<M;i++)
    {
        string tst;
        cin>>tst;
        cout<<password[tst]<<'\n';
    }
    return 0;


}