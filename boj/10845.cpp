#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    list<int> li;
    int N, temp; 
    cin>>N;

    for(int i=0;i<N;i++)
    {
        string order;
        cin>>order;
        if(order=="push")
        {
            cin>>temp;
            li.push_back(temp);
        }
        if(order=="pop")
        {
            if(li.empty())cout<<-1<<endl;
            else
            {
                cout<<li.front()<<endl;
                li.pop_front();
            }
        }
        if(order=="size")
        {
            cout<<li.size()<<endl;
        }
        if(order=="empty")
        {
            cout<<li.empty()<<endl;
        }
        if(order=="front")
        {
            if(li.empty())cout<<-1<<endl;
            else
            {
                cout<<li.front()<<endl;
            }
        }
        if(order=="back")
        {
            if(li.empty())cout<<-1<<endl;
            else
            {
                cout<<li.back()<<endl;
            }
        }
    }



}