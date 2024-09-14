#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    vector<int> V;

    for(int i=0;i<9;i++)
    {
        int temp;
        cin>>temp;
        V.push_back(temp);
    }

    sort(V.begin(),V.end());

    for(int i=0;i<9;i++)
    {   
        for(int j=i+1;j<9;j++)
        {
            int sum = 0;
            for(int k=0;k<9;k++)
            {
                if(k==i||k==j)continue;
                sum+=V[k];
            }
            if(sum==100)
            {
                for(int k=0;k<9;k++)
                {
                    if(k==i||k==j)continue;
                    cout<<V[k]<<'\n';
                }
                return 0;
            }
        }
    }



    return 0;
}