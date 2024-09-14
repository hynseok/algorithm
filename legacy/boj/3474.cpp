#include <bits/stdc++.h>
using namespace std;

int arr[12] = {5, 25, 125, 625, 3125, 15625,
                    78125, 390625, 1953125,
                    9765625, 48828125, 244140625};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, temp;
    vector<int> num;

    cin>>T;
    for(int i=0;i<T;i++)
    {
        int ans = 0;
        int N;
        cin>>N;
        
        ans+=N/5;

        for(int j=1;j<12;j++)
        {
            if(N>=arr[j]) ans+=N/arr[j];
        }

        cout<<ans<<'\n';
    }

    return 0;
}