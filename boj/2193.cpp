#include <bits/stdc++.h>
using namespace std;

int N, ans=0;
vector<int> V;

void DFS(int cnt)
{
    if(cnt==N)
    {
        ans++;
        return;
    }

    if(V.back()==1)
    {
        V.push_back(0);
        DFS(cnt+1);
    }
    else
    {
        V.push_back(0);
        DFS(cnt+1);
        V.pop_back();
        V.push_back(1);
        DFS(cnt+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>N;
    V.push_back(1);
    DFS(1);
    cout<<ans;
    
    return 0;

}