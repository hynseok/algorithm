#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    int ans = 0;
    cin>> N>> M;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++)
    {
        int sum=0;
        sum+=arr[i];
        if(sum==M)
        {
            ans++;
            continue;
        }
        for(int j=i+1;j<N;j++)
        {
            sum+=arr[j];
            if(sum==M)
            {
                ans++;
                break;
            }
            if(sum>M)
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;

}