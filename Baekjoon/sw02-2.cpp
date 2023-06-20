#include <bits/stdc++.h>
using namespace std;

string N;
int T;
char n1,n2;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    int n=1;
    while(T--)
    {
        string ans="";
        cin>>N>>n2>>n1;
        int length = N.length();
        
        int tok=0;//작다 토큰

        if(N[0]>=n1)
        {
            ans+=n1;
            if(N[0]>n1)tok = 1;
        }
        else if(N[0]>=n2)
        {
            ans+=n2;
            if(N[0]>n2)tok = 1;
        }
        else
        {
            ans+='0';
            tok = 1;
        }

        for(int i=1;i<length;i++)
        {
            if(tok==1)
            {
                ans+=n1;
                continue;
            }
            if(N[i]>=n1)
            {
                ans+=n1;
                if(N[i]>n1)tok = 1;
            }
            else if(N[i]>=n2)
            {
                ans+=n2;
                if(N[i]>n2)tok = 1;
            }
            else
            {   
                int leng = ans.length();
                if(ans[leng-1]>n2)
                {
                    ans[leng-1] = n2;
                    ans+=n1;
                    tok=1;
                }   
                else
                {
                    ans="";
                    for(int i=0;i<leng;i++) ans+=n1;
                    tok=1;
                }
                
            }
        }

        if(ans[0]=='0') ans = ans.substr(1,ans.length()-1);
        
        if(ans.length())cout<<'#'<<n<<' '<<ans<<'\n';
        else cout<<'#'<<n<<' '<<"-1"<<'\n';
        n++;
    }

    
}