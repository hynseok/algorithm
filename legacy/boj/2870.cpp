#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2)
{
    if(s1.length()<s2.length()) return true;
    else if(s1.length()==s2.length())
    {
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]==s2[i]) continue;
            if(s1[i]<s2[i]) return true;
            else return false;
        }
    }
    return false;
}

string erase_zero(string s)
{
    if(s.length()==1&&s[0]=='0')
    {
        return s;
    }
    
    while(s[0]=='0')
    {
        s = s.substr(1);
 
        if(s.length()==1&&s[0]=='0')
        {
            return s;
        }
    }
    
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;  
    vector<string> V;
    string S, num;

    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        num="";
        cin>>S;
        for(int idx = 0;idx<S.length();idx++)
        {
            if(!isdigit(S[idx])) 
            {
                if(num!="")
                {
                    num = erase_zero(num);
                    V.push_back(num);
                    num = "";
                }
                continue;
            }
            else
            {
                num += S[idx];
            }
            if(idx==S.length()-1)
            {
                if(num!="")
                {
                    num = erase_zero(num);
                    V.push_back(num);
                }
            }
        }
    }
    
    if(!V.empty())
    {
        sort(V.begin(),V.end(),compare);
    
        for(int i=0;i<V.size();i++)
        {
            cout<<V[i]<<'\n';
        }
    }

    return 0;
}