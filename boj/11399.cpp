#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    vector<int> P; 
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        P.push_back(temp);
    }
    sort(P.begin(),P.end());
    int k=0, ans=0;
    for(int i=0;i<N;i++)
    {
        k+=P[i];
        ans+=k;
    }
    cout<<ans;
    return 0;
}