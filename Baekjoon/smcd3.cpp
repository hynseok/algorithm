#include <bits/stdc++.h>
using namespace std;

int N, M; //N<=M
int C;
int xMap[1004]; //N
int yMap[1004]; //M
int visited[1004];
int W[17][17] = {0, };

void find(int start)
{
    for(int i=start;i<=)
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin>>a>>b>>C;

    for(int i=1;i<=C;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin>>W[i][j];
        }
    }

    if(a<=b)
    {
        N=a; M=b;
        for(int i=0;i<N;i++)
        {
            cin>>xMap[i];
        }
        for(int i=0;i<M;i++)
        {
            cin>>yMap[i];
        }
    }
    else
    {
        N=b; M=a;
        for(int i=0;i<M;i++)
        {
            cin>>yMap[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>xMap[i];
        }
    }
    
    

    return 0;
}