#include <bits/stdc++.h>
using namespace std;

int divide(int N)
{
    if(N%2==0) return N/2;
    else return N/2 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    int N;
    int a, b;
    cin>>N>>a>>b;
    
    while(a!=b)
    {
        ans++;
        N = divide(N);
        a = divide(a);
        b = divide(b);
    }
    cout<< ans;
    return 0;
}