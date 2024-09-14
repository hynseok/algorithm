#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string A, B;
    cin>>A>>B;
    reverse(A.begin(),A.end()); reverse(B.begin(),B.end());
    int a, b;
    a = stoi(A);
    b = stoi(B);
    if(a<b)cout<<b;
    else cout<<a;

}