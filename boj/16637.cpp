#include <bits/stdc++.h>
using namespace std;

int N,ncal;
char formula[20];
vector<char> vcal;
vector<int> vnum;
int cal[10] = {0,}; //visited
int ans = -2147483647;

int calculate(int a, char cal, char b)
{
     if(cal=='+')
    {
        return a+(b-'0');
    }
    else if(cal=='-')
    {
        return a-(b-'0');
    }
    else if(cal=='*')
    {
        return a*(b-'0');
    }

    return 0;
}

int calculate2(int a, char cal, int b)
{
     if(cal=='+')
    {
        return a+b;
    }
    else if(cal=='-')
    {
        return a-b;
    }
    else if(cal=='*')
    {
        return a*b;
    }

    return 0;
}

void dfs(int now)
{
    if(now==ncal)
    {
        vcal.clear();
        vnum.clear();
        int formL = N;
        for(int i=0;i<N;i++)
        {
            if(i==0) {vnum.push_back((formula[i]-'0')); continue;}

            if(i%2==1)
            {
                if(cal[i/2]==1)
                {
                    int calnum = calculate(vnum.back(),formula[i],formula[i+1]);
                    vnum.pop_back();
                    vnum.push_back(calnum);
                    i += 1;
                    formL -= 2;
                }
                else
                {
                    vcal.push_back(formula[i]);
                }
            }
            else
            {
                vnum.push_back((formula[i]-'0'));
            }

        }
        
        int buf=0;
        for(int i=0;i<formL;i++)
        {
            if(i==0) {buf+= vnum[i]; continue;}
            
            if(i%2==1) 
            {
                buf = calculate2(buf,vcal[i/2],vnum[i/2+1]);
            }
           
        }
        if(ans<buf)ans=buf;
        return;

    }

    dfs(now+1);
    if(now==0)
    {   
        cal[now] = 1;
        dfs(now+1);
    }
    else
    {
        if(cal[now-1]==0)
        {
            cal[now] = 1;
            dfs(now+1);
        }
    }
    cal[now] = 0;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    cin>>formula;
    ncal = N/2;
    
    dfs(0);
    cout<<ans;
    return 0;
}