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

Node head[5];

void freeAll(int i){
    Node* curr = head[i].next;
    while(curr!=nullptr){
        Node* next = curr->next;
        free(curr);
        curr = next;
    } 
    head[i].next = nullptr;
}
void init()
{    
    for(int i=0;i<5;i++) freeAll(i);
}

void hire(int mID, int mTeam, int mScore)
{
    Node* node = new Node;
    node->mID = mID; node->mScore = mScore; node->mTeam = mTeam;
    node->next = head[mTeam-1].next;
    head[mTeam-1].next = node;
}

void fire(int mID)
{
    for(int i=0;i<5;i++){
        Node* prev_ptr = &head[i];
        while(prev_ptr->next!=nullptr&&prev_ptr->next->mID!=mID){
            prev_ptr = prev_ptr->next;
        }

        if(prev_ptr->next != nullptr&&prev_ptr->next->mID==mID){
            Node* del = prev_ptr->next;
            prev_ptr->next = prev_ptr->next->next;
            free(del);
            break;
        }
    }
}

void updateSoldier(int mID, int mScore)
{
    for(int i=0;i<5;i++){
        Node* curr_ptr = head[i].next;
        while(curr_ptr!=nullptr&&curr_ptr->mID!=mID){
            curr_ptr = curr_ptr->next;
        }

        if(curr_ptr!= nullptr&&curr_ptr->mID==mID){
            curr_ptr->mScore = mScore;
            break;
        }
    }
}

void updateTeam(int mTeam, int mChangeScore)
{
    Node* curr_ptr = head[mTeam-1].next;
 
    while(curr_ptr!=nullptr){
        int tempScore = curr_ptr->mScore + mChangeScore;
        if(tempScore>5) curr_ptr->mScore = 5;
        else if(tempScore<1) curr_ptr->mScore = 1;
        else curr_ptr->mScore = tempScore;
        curr_ptr = curr_ptr->next;
    }
}

int bestSoldier(int mTeam)
{
    int MaxScore = -1;
    int MaxId = -1;
    Node* curr_ptr = head[mTeam-1].next;

    while(curr_ptr!=nullptr){
        if(MaxScore<curr_ptr->mScore){
            MaxScore = curr_ptr->mScore;
            MaxId = curr_ptr->mID;
        }
        else if(MaxScore==curr_ptr->mScore){
            if(MaxId<curr_ptr->mID) MaxId = curr_ptr->mID;
        }
        curr_ptr = curr_ptr->next;
    }

    return MaxId;
}