#include <bits/stdc++.h>
using namespace std;

int Paper[129][129];
int color[2]={0,}; //color[0] = white, color[1] = blue

bool is_right(int x, int y, int size)
{
    int Tcolor = Paper[y][x];
    for(int i=y;i<y+size;i++)
    {
        for(int j=x;j<x+size;j++)
        {
            if(Paper[i][j]!=Tcolor)
                return false;
        }
    }
    
    return true;
}

void cut(int x, int y, int size)
{
    if(is_right(x,y,size))
    {
        int Tcolor = Paper[y][x];
        color[Tcolor]++;
        return;
    }
    else
    {
        cut(x,y,size/2);
        cut(x,y+size/2,size/2);
        cut(x+size/2,y,size/2);
        cut(x+size/2,y+size/2,size/2);
    }

    

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int temp;
            cin>>temp;
            Paper[i][j]=temp;
        }
    }

    cut(0,0,N);

    cout<<color[0]<<'\n'<<color[1]<<'\n';

    return 0;
}