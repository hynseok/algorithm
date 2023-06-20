#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int dist = 0;
vector<int> apple;
int Map[11];

void search(int left,int cnt)
{
    if(cnt==J)return;
    int right = left + M - 1;
    if(right>N)return;
    if(apple[cnt]>=left&&apple[cnt]<=right)
    {
        search(left,cnt+1);
    }
    else if(apple[cnt]>right)
    {
        
        for(;right<N;)
        {
            dist++;
            right++;
            left++;
            if(right==apple[cnt])
            {
                search(left,cnt+1);
                break;
            }
        }
    }
    else if(apple[cnt]<left)
    {
        for(;left>1;)
        {
            dist++;
            left--;
            right--;
            if(left==apple[cnt])
            {
                search(left,cnt+1);
                break;
            }
        }
    }
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    cin>>N>>M>>J;

    for(int i=0;i<J;i++)
    {
        int idx;
        cin>>idx;
        apple.push_back(idx);
    }
    
    search(1,0);

    cout<<dist<<'\n';

    return 0;
}