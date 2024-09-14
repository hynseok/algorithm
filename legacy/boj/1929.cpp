#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;

    cin >> M >> N;

    bool *primeArray = new bool[N+1];

    for (int i=2;i<=N;i++)
    {
        primeArray[i] = true;
    }

    for (int i=2;i*i<=N;i++)
    {
        if(primeArray[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                primeArray[j]=false;
            }
        }
    }

    for(int i=M;i<=N;i++)
    {
        if(primeArray[i])
            cout<<i<<'\n';
    }


    return 0;

}