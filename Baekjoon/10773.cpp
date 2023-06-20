#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K, ans=0;
    stack<int> stk;
    cin>>K;

    for(int i=0;i<K;i++)
    {
        int temp;
        cin>>temp;
        if(temp==0)
            stk.pop();
        else    
            stk.push(temp);
    }
    int iter = stk.size();
    for(int i=0;i<iter;i++)
    {
        ans+=stk.top();
        stk.pop();
    }
    cout<<ans;
}