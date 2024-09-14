#include <bits/stdc++.h>
using namespace std;

string N;
int T;
char x,y;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    int n=1;
    while(T--)
    {
        string ans="";
        cin>>N>>x>>y;
        int length = N.length();
        
        int tok=0;//작다 토큰

        for(int i=0;i<length;i++)
        {
            if(tok==1)
            {
                ans+=y;
                continue;
            }
            if(N[i]>=y)
            {
                ans+=y;
                if(N[i]>y)tok = 1;
            }
            else if(N[i]>=x)
            {
                ans+=x;
                if(N[i]>x)tok = 1;
            }
            else
            {   
                int leng = ans.length();
                int tok2 = 0;
                for(int j=leng-1;j>=0;j--)
                {
                    if(ans[j]==y)
                    {
                        ans[j]=x;
                        for(int k=j+1;k<leng;k++) ans[k]=y;
                        ans += y;
                        tok = 1;
                        tok2 = 1;
                        break;
                    }
                } 

                if(tok2 == 0)
                {
                    ans="";
                    for(int j=0;j<leng;j++) ans+=y;
                    tok=1;
                }
                
            }
        }

        if(ans[0]=='0') ans = ans.substr(1,ans.length()-1);
        if(ans.length()>0)cout<<'#'<<n<<' '<<ans<<'\n';
        else cout<<'#'<<n<<' '<<"-1"<<'\n';
        n++;
    }

    
}