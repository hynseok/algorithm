#include <bits/stdc++.h>
using namespace std;

bool compare(string A, string B)
{
    if(A.length()<B.length()) return true;
    else if(A.length()==B.length())
    {
        int N = A.length();
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<N;i++)
        {
            if(isdigit(A[i])!=0)
            {
                sum1 += A[i] - '0';
            }
            if(isdigit(B[i])!=0)
            {
                sum2 += B[i] - '0';
            }
        }
        if(sum1<sum2) return true;
        else if(sum1==sum2)
        {
            for(int i=0;i<N;i++)
            {
                if(A[i]==B[i])continue;
                if(A[i]<B[i])return true;
                else return false;
            }
        }
        return false;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
    vector<string> V;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string temp;
        cin>>temp;
        V.push_back(temp);

    }
    sort(V.begin(),V.end(),compare);
    for(int i=0;i<N;i++)
    {
        cout<<V[i]<<'\n';

    }
    return 0;
}