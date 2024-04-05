#include <bits/stdc++.h>
using namespace std;

int N;
int Map[16];
int ans = 0;

bool check(int idx)
{
    for(int i=0;i<idx;i++)
    {
        if(Map[i]==Map[idx]||abs(Map[i]-Map[idx])==idx-i)
            return false;
    }
    return true;
}

void DFS(int idx)
{
    if(idx==N)
    {
        ans++;
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            Map[idx] = i;
            if(check(idx)) DFS(idx+1);
    
        }    

    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    DFS(0);
    cout<<ans;
    return 0;
}