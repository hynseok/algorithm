#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        long long ans = 0;
        int n;
        cin>>n;
        int arr[n+1];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        for(int j=0;j<n;j++)
        {
            int t1 = arr[j];
            for(int k=j+1;k<n;k++)
            {
                int t2 = arr[k];
                ans += gcd(t1,t2);
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}