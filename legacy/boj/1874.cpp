#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    stack <int> s;
    queue <char> ans;
    queue <int> q;

    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }

    for(int i=0;i<n;i++)   
    {
        while(1)
        {
            if(s.empty())
            {
                s.push(q.front());
                q.pop();
                ans.push('+');
            }
            if(s.top()==arr[i])
            {
                s.pop();
                ans.push('-');
                break;
            }
            else
            {
                if(q.empty())
                {
                    cout<<"NO"<<'\n';
                    return 0;
                }
                s.push(q.front());
                q.pop();
                ans.push('+');
            }
            
        }
    }

    int iter = ans.size();
    for(int i=0;i<iter;i++)
    {
        cout<<ans.front()<<'\n';
        ans.pop();
    }
    return 0;


}   