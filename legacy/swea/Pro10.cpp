#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_LEN 200
/////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 200

typedef struct{    
    int coe[10];  //A B C AB AC BC AA BB CC 상수
}expression;

stack<expression> nums;
stack<char> ops;
unordered_map<string,int> Hashmap;
unordered_map<int, expression> midHash;
bool priorityD(char top, char op){
    if (top=='(') return true;
    if (top=='*'&&op=='(') return true;
    if (op == '*'|| op == '(') return true;
    if (op == '-'|| op == '+') return false;
}

void calculate(){
    char op = ops.top();
    ops.pop();
    expression num[3];
    num[0] = nums.top(); nums.pop();
    num[1] = nums.top(); nums.pop();

    if(op == '+'){
        for(int i=0;i<10;i++){
            num[2].coe[i] = num[1].coe[i] + num[0].coe[i];        
        }
    }
    if(op == '-'){
        for(int i=0;i<10;i++){
            num[2].coe[i] = num[1].coe[i] - num[0].coe[i];
        }
    }
    if(op == '*'){
        num[2].coe[0] = num[1].coe[0] * num[0].coe[9] + num[0].coe[0] * num[1].coe[9];
        num[2].coe[1] = num[1].coe[1] * num[0].coe[9] + num[0].coe[1] * num[1].coe[9];
        num[2].coe[2] = num[1].coe[2] * num[0].coe[9] + num[0].coe[2] * num[1].coe[9];
        num[2].coe[3] = num[1].coe[0] * num[0].coe[1] + num[0].coe[0] * num[1].coe[1];
        num[2].coe[4] = num[1].coe[0] * num[0].coe[2] + num[0].coe[0] * num[1].coe[2];
        num[2].coe[5] = num[1].coe[1] * num[0].coe[2] + num[0].coe[1] * num[1].coe[2];
        num[2].coe[6] = num[1].coe[0] * num[0].coe[0];
        num[2].coe[7] = num[1].coe[1] * num[0].coe[1];
        num[2].coe[8] = num[1].coe[2] * num[0].coe[2];
        num[2].coe[9] = num[1].coe[9] * num[0].coe[9];
    }
    nums.push(num[2]);
}

void init()
{
    while(!nums.empty()) nums.pop();
    while(!ops.empty()) ops.pop();
    Hashmap.clear();
    midHash.clear();
}

int addExpression(int mID, char mExpression[MAX_LEN + 1])
{
    while(!nums.empty()) nums.pop();
    while(!ops.empty()) ops.pop();
    
    string raw_exp = (string)mExpression;
    raw_exp = '(' + raw_exp;
    raw_exp += ')';
    int len = raw_exp.size();
    for(int i=0;i<len;i++){
        expression new_exp = {};
        if(raw_exp[i]>='0'&&raw_exp[i]<='5'){
            new_exp.coe[9] = raw_exp[i] - '0';
            nums.push(new_exp);
            continue;
        }
        if(raw_exp[i]=='A'||raw_exp[i]=='B'||raw_exp[i]=='C'){
            int idx = raw_exp[i] - 'A';
            new_exp.coe[idx] = 1;
            nums.push(new_exp);
            continue;
        }
        if(ops.empty()){
            ops.push(raw_exp[i]);
            continue;
        }
        else{
            if(raw_exp[i]==')'){
                while(ops.top()!='('){
                    calculate();
                }
                ops.pop();
                continue;
            }
            if(priorityD(ops.top(),raw_exp[i])){
                ops.push(raw_exp[i]);
            }
            else{
                calculate();
                i--;
            }
        }
        
    }
    expression result = nums.top();
    midHash[mID] = result;

    int isalpha[3] = {0,};
    for(int i=0;i<3;i++){
        if(result.coe[i]!=0)isalpha[i] = 1;
    }
    if(result.coe[3]!=0){
        isalpha[0] = 1;
        isalpha[1] = 1;
    }
    if(result.coe[4]!=0){
        isalpha[0] = 1;
        isalpha[2] = 1;
    }
    if(result.coe[5]!=0){
        isalpha[1] = 1;
        isalpha[2] = 1;
    }
    for(int i=6;i<9;i++){
        if(result.coe[i]!=0)isalpha[i%3] = 1;
    }
    int realN = 0;
    for(int i=0;i<3;i++){
        if(isalpha[i]!=0)realN++;
    }

    string hashKey;
    hashKey += to_string(result.coe[0]); hashKey += 'A'; hashKey +='_';
    hashKey += to_string(result.coe[1]); hashKey += 'B'; hashKey +='_';
    hashKey += to_string(result.coe[2]); hashKey += 'C'; hashKey +='_';
    hashKey += to_string(result.coe[3]); hashKey += "AB"; hashKey +='_';
    hashKey += to_string(result.coe[4]); hashKey += "AC"; hashKey +='_';
    hashKey += to_string(result.coe[5]); hashKey += "BC"; hashKey +='_';
    hashKey += to_string(result.coe[6]); hashKey += "AA"; hashKey +='_';
    hashKey += to_string(result.coe[7]); hashKey += "BB"; hashKey +='_';
    hashKey += to_string(result.coe[8]); hashKey += "CC"; hashKey +='_';
    hashKey += to_string(result.coe[9]);

    int ret;
    if(Hashmap.count(hashKey)){
        ret = Hashmap[hashKey];
        Hashmap[hashKey] = Hashmap[hashKey] + 1;
    }
    else{
        ret = -1 * realN;
        Hashmap[hashKey] = 1;
    }
    
    return ret;
}

int calcExpression(int mID, int mA, int mB, int mC)
{
    int ret = 0;
    expression EXP = midHash[mID];
    int AB = mA * mB;
    int AC = mA * mC;
    int BC = mB * mC;
    int AA = mA * mA;
    int BB = mB * mB;
    int CC = mC * mC;
    
    ret += EXP.coe[0] * mA;
    ret += EXP.coe[1] * mB;
    ret += EXP.coe[2] * mC;
    ret += EXP.coe[3] * AB;
    ret += EXP.coe[4] * AC;
    ret += EXP.coe[5] * BC;
    ret += EXP.coe[6] * AA;
    ret += EXP.coe[7] * BB;
    ret += EXP.coe[8] * CC;
    ret += EXP.coe[9];

    return ret;
}
//////////////////////////////////////////////////////////////
#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_CALC 300

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ret, ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            init();
            ok = true;
        }
        else if (query == CMD_ADD)
        {
            int mID;
            char mExpression[MAX_LEN + 1];
            scanf("%d %s", &mID, mExpression);
            ret = addExpression(mID, mExpression);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_CALC)
        {
            int mID;
            int mA, mB, mC;
            scanf("%d %d %d %d", &mID, &mA, &mB, &mC);
            ret = calcExpression(mID, mA, mB, mC);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}