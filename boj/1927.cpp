#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<int,vector<int>,greater<int>> MH;
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;

        if(x==0)
        {
            if(MH.empty())
                cout<<0<<'\n';
            else
            {
                cout<<MH.top()<<'\n';
                MH.pop(); 
            }
           
        }
        else
        {
            MH.push(x);
        }
       
    }

    return 0;
}