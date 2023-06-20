#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int K, n;
        int arr[14][10000];
        cin >> K >> n;

        for(int j=0;j<=K;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j==0)
                    arr[k-1][j]=k;
                else   
                {
                    int temp=0;
                    for(int l=0;l<k;l++)
                    {
                        temp+=arr[l][j-1];
                    }
                    arr[k-1][j]=temp;
                }

            }
        }
        cout<<arr[n-1][K]<<'\n';
    }
}