#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,temp,ans=0;
    cin >> N;
    vector<int> A; vector<int> B;
    for(int i=0;i<N;i++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    for(int i=0;i<N;i++)
    {
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),compare);

    for(int i=0;i<N;i++)
    {
        ans += A[i]*B[i];
    }

    cout<<ans;

    return 0;


}