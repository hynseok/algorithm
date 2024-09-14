#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v1;
    int N,K;
    
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }

    sort(v1.begin(),v1.end());

    cout<<v1[K-1];

}