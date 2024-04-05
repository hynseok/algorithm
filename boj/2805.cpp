#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector <int> v;
    int N, M,ans=-1;
    long long sum;

    cin>>N>>M;

    int max=0;

    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        if(max<=temp)
            max=temp;
        v.push_back(temp);
    }

    int lo=0; int hi=max;
    int mid;
    while(lo<=hi)
    {
        mid = (hi + lo)/2;
        sum = 0;
        for(int i=0;i<N;i++)
        {
            if(v[i]>mid)
                sum += v[i] - mid;
        }

        if(sum>=M)
        {
            lo = mid+1;
            if(ans<mid)
                ans=mid;
        }
        else
            hi = mid-1;
    }

    cout<<ans;
}