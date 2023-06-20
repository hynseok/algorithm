#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Map;
int N;
//int dp[501] = {0, };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        vector<int> temp;
        for(int j=0;j<i;j++)
        {
            if(i==1)
            {
                int x; cin>>x;
                temp.push_back(x);
                continue;
            }
            else if(i>1)
            {
                if(j==0)
                {
                    int x; cin>>x;
                    temp.push_back(Map[i-2][j]+x);
                }
                if(j>0&&j<i-1)
                {
                    int x; cin>>x;
                    temp.push_back(max(Map[i-2][j-1]+x,Map[i-2][j]+x));
                }
                if(j==i-1)
                {
                    int x; cin>>x;
                    temp.push_back(Map[i-2][j-1]+x);
                }
                
            }
            
        }
        Map.push_back(temp);
    }
    
    sort(Map[N-1].begin(),Map[N-1].end());
    cout<<Map[N-1][N-1];
   /*
   dp[0] = 0;
   int temp; cin>>temp;
   dp[1] = temp;
   for(int i=2;i<=N;i++)
   {
        for(int j=1;j<=i;j++)
        {
            int temp; cin>>temp;
            if(j==1)
            {
                dp[j] += temp;
                continue;
            }
            if(j==i)
            {
                dp[j] = dp[j-1]+temp;
            }
        }
   }
    */
}