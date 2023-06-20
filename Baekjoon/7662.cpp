#include <bits/stdc++.h>
using namespace std;





int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, k; long long n;
    char x;

    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin>>k;
        priority_queue<long long> Max;
        priority_queue<long long> min;
        map<long long,int> Map;

        for(int j=0;j<k;j++)
        {
            cin>>x>>n;

            if(x=='I')
            {
                Max.push(n);
                min.push(-n);
                Map[n]++;
            }
            else
            {
                if(n==1)
                {
                    while(!Max.empty()&&Map[Max.top()]==0)
                    {
                        Max.pop();
                    }

                    if(!Max.empty())
                    {
                        Map[Max.top()]--;
                        Max.pop();
                    }
                }
                else
                {
                    while(!min.empty()&&Map[-min.top()]==0)
                    {
                        min.pop();
                    }
                    if(!min.empty())
                    {
                        Map[-min.top()]--;
                        min.pop();
                    }
                }
            }
        }

        while(!min.empty()&&Map[-min.top()]==0)
        {
            min.pop();
        }                    
        
        while(!Max.empty()&&Map[Max.top()]==0)
        {
            Max.pop();
        }

        if(Max.empty()||min.empty())
        {
            cout<<"EMPTY"<<'\n';
        }
        else
        {
            cout<<Max.top()<<' '<<-min.top()<<'\n';
        }

    }
    return 0;
}