#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> V;
map<int,int> freq;
map<int,int> order;

bool compare(int a, int b)
{
    if(freq[a]>freq[b]) return true;
    else if(freq[a]==freq[b])
    {
        if(order[a]<order[b])return true;
        else return false;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>C;
    int temp;
    int ordernum = 1;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        V.push_back(temp);
        freq[temp]++;
        if(order[temp]==0)
        {
            order[temp] = ordernum;
            ordernum++;
        }
    }

    sort(V.begin(),V.end(),compare);

    for(int i=0;i<V.size();i++)
    {
        cout<<V[i]<<' ';
    }

    return 0;
}