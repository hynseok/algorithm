#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M=1234567891;
    int N, ans=0;
    cin>>N;
    string s;
    cin>>s;

    for(int i=0;i<N;i++)
    {
        long long temp;
        temp = (int)s[i]-96;
        long long temp2 = (temp*(long long)pow(31,i)%M);
        ans += temp2%M;
    }

    cout<<ans;

}