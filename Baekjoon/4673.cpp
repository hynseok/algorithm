#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[10001]={0, };
    int D;
    for(int i=1;i<=10000;i++)
    {
        D = (i + i/1000 + (i%1000)/100 + (i%100)/10 + i%10);
        if(D>10000)break;
        arr[D]++;
    }    

    for(int i=1;i<=9993;i++)
    {
        if(arr[i]==0)
            cout<<i<<'\n';
    }

    return 0;

    
}