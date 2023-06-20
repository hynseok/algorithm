#include <bits/stdc++.h>
using namespace std;



map<int, int> M;

int sum()
{
    int result=0;
    for(auto iter : M)
    {
        result += iter.first * iter.second;
    }
    return result;
}

bool compare(int a, int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K;
    int ans = 0;
    vector<int> coin;
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        coin.push_back(temp);
        M[temp]=0;
    }
    sort(coin.begin(),coin.end(),compare);

    for(int i=0;i<N;i++)
    {
        while(true)
        {
            M[coin[i]]++;
            ans++;
            if(sum()>K)
            {
                M[coin[i]]--;
                ans--;
                break;
            }
            if(sum()==K)
            {
                cout<<ans;
                return 0;
            }
        }
    }
}