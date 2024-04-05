#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char>dummy;
    char temp;
    int ans = 0;
    while(1)
    {
        scanf("%1c",&temp);
        if(temp==' '&&dummy.size()==0) continue;
        dummy.push_back(temp);
        if(temp==' ')ans++;
        if(temp=='\n')
        {
            if(dummy[dummy.size()-2]==' ')ans--;
            if(dummy.size()==1)ans=-1;
            break;
        }
    }
    cout<<ans+1;
}