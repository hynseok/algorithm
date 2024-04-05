#include <bits/stdc++.h>
using namespace std;

int N;
int psum[100004] = {0, };
int Arr[100004] = {0, };
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    int temp;
    for(int i=1;i<=N;i++)
    {
        cin>>temp;
        if(temp==1)Arr[i] = 1;
        else Arr[i] = -1;
    }

    psum[0] = 0;
    for(int i=1;i<=N;i++)
    {
        psum[i] = psum[i-1] + Arr[i];
        
    }
    
    int Min = 987654321;
    int Max = -987654321;
    for(int i=0;i<=N;i++)
    {
        Min = min(Min,psum[i]);
        Max = max(Max,psum[i]);
    }

    cout<<Max-Min<<'\n';

    return 0;  
}