#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<int> Q;
    int N, K, temp;
    cin >> N >> K;
    for(int i=1;i<=N;i++)  
    {
        Q.push(i);
    }  
    cout<<"<";
    while(Q.size()>1)
    {
        for(int i=0;i<K-1;i++)
        {
            temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        cout<<Q.front()<<", ";
        Q.pop();
    }
    cout<<Q.front()<<">";
    return 0;
}