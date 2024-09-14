#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A, B, V;
    int ans;
    cin>>A>>B>>V;
    ans = (V-B-1)/(A-B) +1;


    cout<<ans;

}