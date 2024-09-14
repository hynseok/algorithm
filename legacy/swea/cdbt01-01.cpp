#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

extern void init();
extern void hire(int mID, int mTeam, int mScore);
extern void fire(int mID);
extern void updateSoldier(int mID, int mScore);
extern void updateTeam(int mTeam, int mChangeScore);
extern int bestSoldier(int mTeam);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}

#include<iostream>
#include<cstring>

struct Node{
    int mID;
    int mScore;
    int mTeam;
    Node* next;
};

int nodeCnt = 0;
Node Soldiers[100001];
Node head;

Node* new_node(int mID, int mTeam, int mScore){
    Soldiers[nodeCnt].mID = mID;
    Soldiers[nodeCnt].mTeam = mTeam;
    Soldiers[nodeCnt].mScore = mScore;
    Soldiers[nodeCnt].next = nullptr;

    return &Soldiers[nodeCnt++];
}

void init()
{
    if(nodeCnt>0) memset(Soldiers,0,sizeof(Soldiers));
    head.next = nullptr;
    nodeCnt = 0;
}

void hire(int mID, int mTeam, int mScore)
{
    Node* node = new_node(mID, mTeam, mScore);
    node->next = head.next;
    head.next = node;
}

void fire(int mID)
{
    Node* prev_ptr = &head;
    while(prev_ptr->next!=nullptr&&prev_ptr->next->mID!=mID){
        prev_ptr = prev_ptr->next;
    }

    if(prev_ptr->next != nullptr){
        prev_ptr->next = prev_ptr->next->next;
    }
}

void updateSoldier(int mID, int mScore)
{
    Node* curr_ptr = head.next;
    while(curr_ptr!=nullptr){
        if(curr_ptr->mID==mID) break;
        curr_ptr = curr_ptr->next;
    } 
    if(curr_ptr!=nullptr){
        curr_ptr->mScore = mScore;
    }
}

void updateTeam(int mTeam, int mChangeScore)
{
    Node* curr_ptr = head.next;
    while(curr_ptr!=nullptr){
        if(curr_ptr->mTeam==mTeam){
            int tempScore = curr_ptr->mScore + mChangeScore;
            if(tempScore>5) curr_ptr->mScore = 5;
            else if(tempScore<1) curr_ptr->mScore = 1;
            else curr_ptr->mScore = tempScore;
        }
        curr_ptr = curr_ptr->next;
    }
}

int bestSoldier(int mTeam)
{
    int MaxScore = -1;
    int MaxId = -1;
    Node* curr_ptr = head.next;
    while(curr_ptr!=nullptr){
        if(curr_ptr->mTeam==mTeam){
            if(MaxScore<curr_ptr->mScore){
                MaxScore = curr_ptr->mScore;
                MaxId = curr_ptr->mID;
            }
            else if(MaxScore==curr_ptr->mScore){
                if(MaxId<curr_ptr->mID) MaxId = curr_ptr->mID;
            }
        }
        curr_ptr = curr_ptr->next;
    }
    return MaxId;
}