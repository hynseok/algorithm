#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, sugar;
    cin>>N;
    sugar = N;
    
    int kg5=sugar/5;
    int kg3=0;
    for(kg5;kg5>=0;kg5--)
    {
        int sug=sugar-(kg5*5);
        if(sug==0)
        {
            cout<<kg5;
            return 0;
        }
        if(sug%3==0)
        {
            kg3=sug/3;
            break;
        }
    }

    if(kg3==0)
    {
        cout<<-1;
    }
    else
        cout<<kg5+kg3;
    
}