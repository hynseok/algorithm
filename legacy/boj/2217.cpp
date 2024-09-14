#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,tw;
    cin>>N;
    int w[100001];

    for(int i=0;i<N;i++)
    {
        cin>>tw;
        w[i]=tw;
    }

    sort(w,w+N,compare);

    int ans = 0;
    for(int i=0;i<N;i++)
    {
        if(ans<w[i]*(i+1))
            ans = w[i]*(i+1);

    }

    cout<<ans;
    return 0;



}