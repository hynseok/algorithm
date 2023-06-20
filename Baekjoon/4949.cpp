#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    while(1)
    {
        getline(cin,str);
        
        if(str==".")
            break;
        
        stack<char> stk;
        int tok = 0;
        
        for(int i=0;i<str.length();i++)
        {
            char temp = str[i];
            if(temp=='('||temp=='{'||temp=='[')
            {
                stk.push(temp);
            }
            if(temp==')')
            {   
                if(stk.empty())
                {
                    tok=1;
                    break;
                }
                if(stk.top()=='(')
                    stk.pop();
                else
                    tok=1;

            }
            if(temp=='}')
            {
                if(stk.empty())
                {
                    tok=1;
                    break;
                }
                if(stk.top()=='{')
                    stk.pop();
                else
                    tok=1;
            }
            if(temp==']')
            {
                if(stk.empty())
                {
                    tok=1;
                    break;
                }
                if(stk.top()=='[')
                    stk.pop();
                else
                    tok=1;
            }
            
        }
        if(tok==0&&stk.size()==0)
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
    }
}