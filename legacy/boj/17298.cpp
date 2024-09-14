#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[1000004];
int ret[1000004];
stack<int> s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin>>N;
    memset(ret,-1,sizeof(ret));

    for(int i=0;i<N;i++)
    {
        cin>>Arr[i];
        while(s.size()&&Arr[s.top()]<Arr[i])
        {
            ret[s.top()] = Arr[i]; s.pop();
        }
        s.push(i);
    }

    for(int i=0;i<N;i++)
    {
        cout<<ret[i]<<' ';
    }
    return 0;
}