#include <bits/stdc++.h>
using namespace std;

double distance(pair<int,int> a, pair<int, int> b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   

    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        pair<int,int> start, end;
        cin>>start.first>>start.second>>end.first>>end.second;

        int n; 
        cin>>n;
        vector<pair<int,pair<int,int> > > galaxy(n);
        for(int j=0;j<n;j++)
        {
            int x, y, r;
            cin>>x>>y>>r;
            galaxy[j] = make_pair(r,make_pair(x,y));
        }
        sort(galaxy.begin(),galaxy.end());
        vector<bool> start_list(n), end_list(n);
        for(int j=0;j<n;j++)
        {
            if(distance(start,galaxy[j].second)<galaxy[j].first)
                start_list[j] = true;
            if(distance(end,galaxy[j].second)<galaxy[j].first)
                end_list[j] = true;
        }

        int answer = 0;
        for(int j=0;j<n;j++)
        {
            if(start_list[j]&&end_list[j])
            break;
            if(start_list[j]||end_list[j])
            answer++;
        }
        cout<<answer<<'\n';
    }
    return 0;
}