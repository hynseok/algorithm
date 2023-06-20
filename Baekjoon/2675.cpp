#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >>T;
    for(int i=0;i<T;i++)
    {
        int R;
        cin>>R;
        string P;
        cin>>P;
    
        for(int j=0;j<P.size();j++)
        {
            for(int k=0;k<R;k++)
            {
                cout<<P[j];
            }
        }
        cout<<'\n';
        
    }
    return 0;
}