#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int Ans = -999999; 
int numArr[1000];
int visited[1000]={0,};
int N;

void dfs(int idx)
{
    if(idx==N-1)
    {
        int temp = ans.size();
        Ans = max(Ans, temp);
        return;
    }

    for(int i=idx;i<N;i++)
    {
        if(!ans.empty())
        {
            if(ans.back()>=numArr[i]||visited[i]==1) continue;
        }

        ans.push_back(numArr[i]);
        visited[i]=1;
        dfs(i);
        ans.pop_back();
        visited[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>numArr[i];
    }

    dfs(0);
    cout<<Ans;
    

}