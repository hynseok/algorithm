#include <bits/stdc++.h>
using namespace std;

int N,K;
int temp[100001];
vector <int> sum;
int Sum = 0;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   

    cin>>N;
    cin>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>temp[i];
    }

    for(int i=1;i<=K;i++)
    {
        Sum += temp[i];
    }
    sum.push_back(Sum);

    for(int i=K;i<=N-1;i++)
    {
        Sum-=temp[i-K+1];
        Sum+=temp[i+1];
        sum.push_back(Sum);
    }

    sort(sum.begin(),sum.end());
    cout<<sum.back()<<'\n';


    return 0;
}