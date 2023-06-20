#include <bits/stdc++.h>
using namespace std;

vector<int> V;

bool check(int x)
{
    if(V.empty())
        return false;

    if(find(V.begin(),V.end(),x)!=V.end())
        return true;
    else   
        return false;
}

void empty()
{
    while(!V.empty())
    {
        V.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M;
    cin>>M;

    for(int i=0;i<M;i++)
    {
        string S;
        int x;

        cin>>S;

        if(S=="all")
        {
            empty();
            for(int i=1;i<=20;i++)
            {
                V.push_back(i);
            }
            continue;
        }
        if(S=="empty")
        {
            empty();
            continue;
        }
        cin>>x;
        if(S=="add"&&check(x)==false)
        {
            V.push_back(x);
        }
        if(S=="remove"&&check(x)==true)
        {
            V.erase(find(V.begin(),V.end(),x));
        }
        if(S=="check")
        {
            cout<<check(x)<<'\n';
        }
        if(S=="toggle")
        {
            if(check(x))
            {
                V.erase(find(V.begin(),V.end(),x));
            }
            else
            {
                V.push_back(x);
            }
        }
        
    }

}