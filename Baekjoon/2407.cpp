#include <bits/stdc++.h>
using namespace std;

string arr[101][101];

string add(string a, string b)
{
    string ret = "";
    int sum = 0;
    int size = max(a.size(),b.size());

    for(int i=0;i<size||sum;i++)
    {
        if(a.size()>i) sum += a[i] - '0';
        if(b.size()>i) sum += b[i] - '0';

        ret += sum%10 + '0';
        sum /= 10;
    }

    return ret;
}

string combi(int a, int b)
{
    if(a==b||b==0)
        return "1";
    string &ans = arr[a][b];
    if(ans!="") return ans;
    ans = add(combi(a-1,b-1),combi(a-1,b));
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    int a,b;
    cin>>a>>b;
    string s = combi(a,b);
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
