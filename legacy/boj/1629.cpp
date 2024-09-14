#include <bits/stdc++.h>
using namespace std;
//pow(A,B) mod C;
long long A, B, C; 

long long cal(long long num, long long cnt)
{
    if(cnt==1) return num%C;
    else
    {
        long long x = cal(num, cnt/2)%C;
        if(cnt%2==0) return x*x%C;
        else return x*x%C*num%C;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>A>>B>>C;    
    

    cout<<cal(A,B);
}