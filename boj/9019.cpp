#include <bits/stdc++.h>
using namespace std;

string tostring(int n);
string BFS(int A, int B);
string D(string s);
string S(string s);
string L(string s);
string R(string s);

int visited[10000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //input
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        int A, B;
        cin>>A>>B;
        //solve
        cout<<BFS(A,B)<<'\n';
    }

}

string tostring(int n)
{
    string S = to_string(n);
    if(S.size()==1) return "000"+S;
    else if(S.size()==2) return "00"+S;
    else if(S.size()==3) return "0"+S;
    else return S;
}

string D(string s)
{
    int temp = stoi(s);
    return tostring((temp*2)%10000);
}

string S(string s)
{
    int temp = stoi(s);
    if(temp == 0) return "9999";
    return tostring(temp-1);
}

string L(string s)
{
    char temp = s[0];
    s[0] = s[1]; s[1] = s[2]; s[2] = s[3]; s[3] = temp;
    return s;
}

string R(string s)
{
    char temp = s[3];
    s[3] = s[2]; s[2] = s[1]; s[1] = s[0]; s[0] = temp;
    return s;
}


string BFS(int A, int B)
{
    string stringA = tostring(A);
    string stringB = tostring(B);
    string ret;
    queue<pair<string,string>> Q;
    Q.push({stringA,""});
    visited[stoi(stringA)]=1;

    while(!Q.empty())
    {
        pair<string,string> temp;
        temp = Q.front();
        Q.pop();

        if(temp.first==stringB)
        {
            ret = temp.second;
            break;
        }

        string next[4];
        next[0] = D(temp.first);
        next[1] = S(temp.first);
        next[2] = L(temp.first);
        next[3] = R(temp.first);

        for(int i=0;i<4;i++)
        {
            if(visited[stoi(next[i])]==0)
            {
                if(i==0) Q.push({next[i],temp.second+"D"});
                if(i==1) Q.push({next[i],temp.second+"S"});
                if(i==2) Q.push({next[i],temp.second+"L"});
                if(i==3) Q.push({next[i],temp.second+"R"});

                visited[stoi(next[i])] = 1;
            }
        }

        
    }
    return ret;
}