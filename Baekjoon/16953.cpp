#include <bits/stdc++.h>
using namespace std;

int A, B;
int tok=0;
vector<int> V;
void DFS(int cnt)
{   

    if(V.back()==B)
    {
        cout<<cnt+1;
        tok = 1;
        return;
    }
    if(V.back()>B)
    {
        return;
    }
    
    int temp1 = V.back()*2;
    V.push_back(temp1);
    DFS(cnt+1);
    V.pop_back();

    int temp2 = V.back()*10 + 1;
    V.push_back(temp2);
    DFS(cnt+1);
    V.pop_back();


}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>A>>B;
    V.push_back(A);
    DFS(0);
    if(tok==0) cout<<-1;

    return 0;
}