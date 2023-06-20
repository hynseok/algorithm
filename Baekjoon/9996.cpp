#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    
    int N;
    cin>>N;

    string Pattern;
    string P1, P2;

    cin>>Pattern;
    P1 = Pattern.substr(0,Pattern.find('*'));
    P2 = Pattern.substr(Pattern.find('*')+1);
    

    for(int i=0;i<N;i++)
    {
        string temp;
        cin>>temp;
        if(temp.size()<P1.size()+P2.size())
        {
            cout<<"NE"<<'\n';
            continue;
        }
        if((temp.substr(0,P1.size())==P1)&&(temp.substr(temp.size()-P2.size())==P2))
        {
            cout<<"DA"<<'\n';
        }
        else cout<<"NE"<<'\n';
    }



    return 0;
}