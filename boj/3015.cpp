#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    long long arr[N+1];
    long long ans=0;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++)
    {
        long long token = 0;
        for(int j=i+1;j<N;j++)
        {
            if(token==0)
            {
                token=arr[j];
                ans++;
                if(arr[j]>arr[i])break;
            }
            else
            {
                if(arr[j]>=token)
                {       
                    ans++;
                    token = max(arr[j],token);
                }
                else
                {
                    break;
                }
            }
            
        }

    }   
    cout<<ans;
    return 0;
}