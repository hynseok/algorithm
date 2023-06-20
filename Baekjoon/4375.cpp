#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    int n;

    while(cin>>n)
    {
        int temp;
        for(int i=1;i<=n;i++)
        {
            temp = temp*10+1;
            temp%=n;
            if(temp==0)
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}