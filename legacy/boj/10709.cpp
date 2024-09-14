#include <bits/stdc++.h>
using namespace std;

int H, W;
int Map[101][101];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>H>>W;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            Map[i][j] = -1;
        }
    }

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            char temp;
            cin>>temp;
            if(temp=='c')
            {
                Map[i][j]=0;
            }
        }
    }

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(Map[i][j]==-1) continue;
            if(Map[i][j]!=-1&&j!=(W-1))
            {
                if(Map[i][j+1]!=0)Map[i][j+1] = Map[i][j] + 1;
            } 
        }
    }

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cout<<Map[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}