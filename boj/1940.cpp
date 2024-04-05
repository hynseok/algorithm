#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    int N, M, sum,ans=0;;
    int mat[15000]={0, };

    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>mat[i];
    }

    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            sum = mat[i] + mat[j];
            if(sum==M) ans++;
        }
    }
    cout<<ans;
    return 0;
}