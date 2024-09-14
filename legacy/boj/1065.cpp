#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin>>N;
    if(N<100)
    {
        cout<<N<<'\n';
    }
    else
    {
        int ans = 99;
        
        for(int i=100;i<=N;i++)
        {
            int a = i/100;
            int b = (i%100)/10;
            int c = (i%10);
            if((a-b)==(b-c))
                ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}