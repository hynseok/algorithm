#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    int A, B, C;
    int fee = 0;
    int time[101]={0,};
    cin>>A>>B>>C;

    for(int i=0;i<3;i++)
    {
        int t1, t2;
        cin>>t1>>t2;
        for(int i=t1;i<t2;i++)
        {
            time[i]++;
        }
    }
    for(int i=1;i<=100;i++)
    {
        if(time[i]==1) fee += A;
        if(time[i]==2) fee += B*2;
        if(time[i]==3) fee += C*3; 
    }
    cout<<fee<<'\n';
    return 0;
}