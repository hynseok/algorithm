#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    int max=-1;
    cin>>N;
    vector <int> V;

    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        if(max<temp)max=temp;
        V.push_back(temp);
    }


    float sum;
    for(int i=0;i<N;i++)
    {
        sum += V[i];
    }
    sum=sum*100/max;
    float average;
    average = sum/N;

    cout<<average;

}