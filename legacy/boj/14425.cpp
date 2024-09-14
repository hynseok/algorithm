#include <bits/stdc++.h>
using namespace std;

vector<string> V;

int binarysearch(string S)
{
    int begin = 0;
    int end = V.size() - 1;

    while(begin<=end)
    {
        int mid = (begin + end) / 2;

        if(S==V[mid]) return 1;
        else
        {
            if(S<V[mid])
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string temp;
    int N, M, ans=0;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        V.push_back(temp);
    }
    sort(V.begin(),V.end());

    for(int i=0;i<M;i++)
    {
        cin>>temp;
        if(binarysearch(temp)==1) ans++;
    }
    cout<<ans;
    return 0;
}