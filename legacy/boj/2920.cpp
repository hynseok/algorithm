#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int token=0;
    int c1=0, c2=0;
    for(int i=0;i<8;i++)
    {
        int temp;
        cin>>temp;
        if(token==0&&temp==8)
        {   
            token = 1;
            c1 = temp;
        }
        if(token==0&&temp==1)
        {
            token = 1;
            c2 = temp;
        }

        token=1;

        if(c1)
        {
            if(temp == c1-i)continue;
            else
            {
                cout<<"mixed";
                return 0;
            }
        }
        else if(c2)
        {
            if(temp == c2+i)continue;
            else
            {
                cout<<"mixed";
                return 0;
            }
        }
        else
        {
            cout<<"mixed";
            return 0;
        }

    }
    if(c1<c2)
    {
        cout<<"ascending";
    }
    else
    {
        cout<<"descending";
    }
}