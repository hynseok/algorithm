#include <bits/stdc++.h>
using namespace std;

int N;
long long dist[100001];
long long price[100001];
long long sum;
long long greedy;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    cin>>N;
    for(int i=1;i<=N-1;i++)
    {
        cin>>dist[i];
    }
    for(int i=1;i<=N;i++)
    {
        cin>>price[i];
    }
    greedy = 1000000000;
    for(int i=1;i<=N-1;i++)
    {
        if(price[i]<greedy)
            greedy = price[i];
        sum += greedy*dist[i];
    }
    cout<<sum<<'\n';
    return 0;
}