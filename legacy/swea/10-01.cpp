#include <bits/stdc++.h>
using namespace std;

int T, crackDay, Max;
bool StudyArr[1000001];

void Find(int lastDay){
    int start = 1;
    int end = 1;
    int num = 0;
    while(end<lastDay+1){
        if(StudyArr[end]){
            num++;
            end++;
            Max = max(Max,num);
        }
        else{
            if(crackDay==0){
                Max = max(Max,num);
                if(!StudyArr[start]) crackDay++;
                start++;
                num--;
            }
            else{
                crackDay--;
                num++;
                end++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>T;
    for(int tc=1;tc<=T;tc++){
        memset(StudyArr,0,sizeof(StudyArr));
        int n;
        cin>>n>>crackDay;

        int temp, lastDay;
        for(int i=0;i<n;i++){
            cin>>temp;
            StudyArr[temp] = true;
            if(i==n-1) lastDay = temp;
        }
        Max = crackDay+1;
        
        Find(lastDay);
        cout<<'#'<<tc<<' '<<Max<<'\n';
    }
    
    return 0;
}