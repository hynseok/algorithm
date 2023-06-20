#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M, B, temp, ans=0x7f7f7f7f, ansh;
    int map[500][500];
    cin >> N >> M >> B;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>temp;
            map[i][j]=temp;
        }
    }

    for(int h=0;h<=256;h++)
    {
        int build, remove;
        build = 0; remove = 0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int gap = map[i][j]-h;
                if(gap>0)remove+=gap;
                else if(gap<0) build-=gap;
            }
        }

        if(build<=remove+B)
        {
            int tans;
            tans = remove*2 + build;
        
            if(tans<=ans)
            {
                ans = tans;
                ansh = h;
            }
        }
    }

    cout<<ans<<' '<<ansh<<'\n';   
}