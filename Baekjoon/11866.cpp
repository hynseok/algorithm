#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    queue<int> q;
    int N, K;

    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }

    int tmp=0, k;
    cout<<"<";
    while(!q.empty())
    {
        if(tmp==K-1)
        {  
            cout<<q.front();
            if(q.size()==1) cout<<">";
            else cout<<", ";
            q.pop();
            tmp=0;
        }
        else
        {
            k=q.front();
            q.pop();
            q.push(k);
            tmp++;
        }
    }

    

    
}