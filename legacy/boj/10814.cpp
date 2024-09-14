#include <bits/stdc++.h>
using namespace std;

typedef struct Person
{
    string name;
    int old;
}P;

bool compare(P p1, P p2)
{
    return p1.old<p2.old;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    P li[100001];
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>li[i].old>>li[i].name;
    }

    stable_sort(li,li+N,compare);

    for(int i=0;i<N;i++)
    {
        cout<<li[i].old<<' '<<li[i].name<<'\n';
    }


}