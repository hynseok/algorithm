#include <bits/stdc++.h>
using namespace std;

string tostring(int n);
string BFS(int A, int B);
int D(int n);
int S(int n);
int L(int n);
int R(int n);

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

int D(int n)
{
    return (n*2)%10000;
}

int S(int n)
{
    if(n == 0) return 9999;
    return n-1;
}

int L(int n)
{
    return (n%1000)*10 + n/1000;
}

int R(int n)
{
    return (n%10)*1000 + n/10;
}


string BFS(int A, int B)
{
    string ret;
    queue<pair<int,string>> Q;
    Q.push({A,""});
    visited[A]=1;

    while(!Q.empty())
    {
        pair<int,string> temp;
        temp = Q.front();
        Q.pop();

        if(temp.first==B)
        {
            ret = temp.second;
            break;
        }

        int next[4];
        next[0] = D(temp.first);
        next[1] = S(temp.first);
        next[2] = L(temp.first);
        next[3] = R(temp.first);

        for(int i=0;i<4;i++)
        {
            if(visited[next[i]]==0)
            {
                if(i==0) Q.push({next[i],temp.second+"D"});
                if(i==1) Q.push({next[i],temp.second+"S"});
                if(i==2) Q.push({next[i],temp.second+"L"});
                if(i==3) Q.push({next[i],temp.second+"R"});

                visited[next[i]] = 1;
            }
        }

        
    }
    return ret;
}