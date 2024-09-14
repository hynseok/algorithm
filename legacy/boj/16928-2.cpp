#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int Map[101];
    int length[101];

    for(int i=1;i<=100;i++)
    {
        Map[i]=i;
        length[i]=-1;
    }

    int N, M;
    cin>>N>>M;
    for(int i=0;i<N+M;i++)
    {
        int x, y;
        cin>>x>>y;
        Map[x]=y;
    }


    queue<int> Q;
    length[1]=0;
    Q.push(1);

    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for(int i=1;i<=6;i++)
        {
            int y = x+i;
            if(y>100)continue;
            y = Map[y];
            if(length[y]==-1)
            {
                length[y]=length[x]+1;
                Q.push(y); 
            }
        }
    }
    cout<<length[100];
}