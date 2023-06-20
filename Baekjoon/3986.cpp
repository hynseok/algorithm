#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    int N, ans=0;
    vector<string> S;
    string temp;
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        S.push_back(temp);
    }

    for(int i=0;i<N;i++)
    {
        stack<char> STK;
        for(int j=0;j<S[i].size();j++)
        {  
            if(STK.empty())
            {
                STK.push(S[i][j]);
            }
            else
            {
                if(STK.top()==S[i][j]) STK.pop();
                else
                {
                    STK.push(S[i][j]);
                }
            }

        }
        if(STK.empty()) ans++;

    }

    cout<<ans<<'\n';

    return 0;
}