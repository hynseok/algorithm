#include <bits/stdc++.h>
using namespace std;

int pactorial(int a)
{
    if(a==0)
        return 1;
    else
        return a*pactorial(a-1);
}

int combination(int a, int b)
{
    return pactorial(a)/(pactorial(b)*pactorial(a-b));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int ans=1;
        int n;
        map<string,int> wear;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            string x, type;
            cin>>x>>type;
            wear[type]++;
        }

        for(auto i : wear)
        {
            ans *= (i.second+1);
        }

        cout<<ans-1<<'\n';
    }
    return 0;
}