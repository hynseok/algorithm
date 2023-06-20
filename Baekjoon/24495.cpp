#include <bits/stdc++.h>
using namespace std;

int T;
int WD[4]; int LD[4]; 
vector<int> dice;
int DICE[4];
bool flag = false;

int Battle(int D1[], int D2[]){
    int A, ret=0;
    int Win1 = 0, Win2 = 0, Draw = 0;  
    for(int i=0;i<4;i++){
        A = D1[i];    
        for(int j=0;j<4;j++){
            if(A<D2[j])Win2++;
            else if(A==D2[j])Draw++;
            else Win1++;
        }
    }
    if(Win1<Win2) ret = 2;
    else if(Win2<Win1) ret = 1;
    return ret;
}

void MakeDice(int cnt){
    if(cnt==4){
        for(int i=0;i<4;i++) DICE[i] = dice[i];
        if(Battle(WD,DICE)==2&&Battle(LD,DICE)==1)flag = true;
        return;
    }
    for(int i=1;i<=10;i++){
        dice.push_back(i);
        MakeDice(cnt+1);
        dice.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;

    for(int tc=1;tc<=T;tc++){
        flag = false;
        dice.clear();
        int temp1[4], temp2[4];
        for(int i=0;i<4;i++) cin>>temp1[i];
        for(int i=0;i<4;i++) cin>>temp2[i];
        
        int win = Battle(temp1,temp2);
        if(win==1){
            for(int i=0;i<4;i++) WD[i] = temp1[i];
            for(int i=0;i<4;i++) LD[i] = temp2[i];
        }
        else{
            for(int i=0;i<4;i++) WD[i] = temp2[i];
            for(int i=0;i<4;i++) LD[i] = temp1[i];
        }

        MakeDice(0);

        if(flag==true) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';

    }

    return 0;
}