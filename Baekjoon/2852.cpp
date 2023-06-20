#include <bits/stdc++.h>
using namespace std;

int changetoint(string s)
{
    int num = 0;
    num += (atoi(s.substr(0,2).c_str())*60 + atoi(s.substr(3,2).c_str()));
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int team[3] = {0,};
    int winningtime[3] = {0,};
    vector<int> nowtime;
    int goal_team;
    string goal_time;
    int N;

    cin>>N;

    for(int i=0;i<N;i++)
    {   
        cin >> goal_team >> goal_time;
        
        nowtime.push_back(changetoint(goal_time));

        if(team[1]<team[2]) 
        {
            winningtime[2] += nowtime[i] - nowtime[i-1];
        }
        else if(team[2]<team[1])
        {
            winningtime[1] += nowtime[i] - nowtime[i-1];
        } 

        team[goal_team]++;


    }

    if(team[1]<team[2]) 
    {
        winningtime[2] += changetoint("48:00") - nowtime.back();
    }
    else if(team[1]>team[2])
    {
        winningtime[1] += changetoint("48:00") - nowtime.back();
    } 


    string s[3];
    for(int i=1;i<=2;i++)
    {
        string mm,ss;
        mm = "00" + to_string(winningtime[i]/60);
        ss = "00" + to_string(winningtime[i]%60);
        cout<<mm.substr(mm.size()-2,2)+":"+ss.substr(ss.size()-2,2)<<'\n';
    }
    

    return 0;
}