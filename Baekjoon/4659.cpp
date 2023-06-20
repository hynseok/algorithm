#include <bits/stdc++.h>
using namespace std;

bool is_aeiou(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string password;
    int tok; //0 = acceptable, 1 = not acceptable
    int aeiou;
    int z3, a3;
    char before;
    while(cin>>password)
    {
        aeiou = 0;
        before = 'A';
        z3 = 0; a3 = 0;
        tok = 0;
        if(password=="end") break;

        for(int i=0;i<password.size();i++)
        {
            if((before!='e'&&before!='o')&&before==password[i])
            {
                tok=1;
                break;
            }
            if((z3==2&&!is_aeiou(password[i]))||(a3==2&&is_aeiou(password[i])))
            {
                tok=1;
                break;
            }
            if(is_aeiou(password[i]))
            {
                aeiou++;
                before = password[i];
                z3=0;
                a3++;
            }
            else
            {
                before = password[i];
                z3++;
                a3=0;
            }
        }
        if(aeiou==0) tok=1;

        if(tok)
        {
            cout<<'<'<<password<<'>'<<" is not acceptable."<<'\n';
        }
        else
        {
            cout<<'<'<<password<<'>'<<" is acceptable."<<'\n';
        }
    }

    return 0;
}