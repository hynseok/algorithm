#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B;
    int tok=0;
    int cnt=0;
    
    cin>>A>>B;

    while(B>=A)
    {
        if(B==A)
        {
            cout<<cnt+1;
            tok=1;
            break;
        }    

        if(B%10 == 1)
        {
            B /= 10;
            cnt++;
            continue;
        }
        if(B%2==1)
        {
            break;
        }
        else B/=2;
        cnt++;

    }

    if(tok==0) cout<<-1;

    return 0;
}