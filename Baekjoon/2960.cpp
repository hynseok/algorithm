#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    int is_delete[1001]={0,};
    vector<int> v;
    cin>>N>>K;
    for(int i=2;i<=N;i++)
    {
        if(is_delete[i]==0)
        {
            is_delete[i]=1;
            v.push_back(i);
            for(int j=i+i;j<=N;j+=i)
            {
                if(is_delete[j]==0)
                {
                    is_delete[j]=1;
                    v.push_back(j);
                }
            }
        }
    }
    cout<<v[K-1];
    return 0;
}