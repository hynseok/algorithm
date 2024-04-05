#include <bits/stdc++.h>
using namespace std;

unsigned long long pactorial(unsigned long long n)
{
    if(n==0)
        return 1;
    return n * pactorial(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;

    for(int i=0;i<T;i++)
    {
        unsigned long long t1, t2;
        cin>>t1 >> t2;
        if(t1>(t2/2))
        {
            t1=t2-t1;
        }
        int k=0; unsigned long long P=1;
        for(int j=t2;k<t1;j--)
        {
            P*=j; k++; 
        }
        P/=pactorial(t1);
        cout<<P<<'\n';
    }   
    return 0;
}