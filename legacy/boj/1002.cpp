#include <bits/stdc++.h>
using namespace std;

struct circle
{
    int x;
    int y;
    int r;
};

void ans(circle A, circle B)
{
    if(A.x==B.x&&A.y==B.y&&A.r==B.r)
    {
        cout<<-1<<'\n';
        return;
    }

    int dist;
    dist = pow((A.x-B.x),2)+pow((A.y-B.y),2);
    if(dist<pow((A.r-B.r),2))
    {
        cout<<0<<'\n';
        return;
    }
    if(dist==pow((A.r-B.r),2))
    {
        cout<<1<<'\n';
        return;
    }
    if(dist>pow((A.r-B.r),2)&&pow((A.r+B.r),2)>dist)
    {
        cout<<2<<'\n';
        return;
    }
    if(pow((A.r+B.r),2)==dist)
    {
        cout<<1<<'\n';
        return;
    }
    if(pow((A.r+B.r),2)<dist)
    {
        cout<<0<<'\n';
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        circle A, B;
        cin>>A.x>>A.y>>A.r>>B.x>>B.y>>B.r;
        ans(A,B);
    }
    return 0;
}