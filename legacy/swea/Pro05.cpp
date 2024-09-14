#include <bits/stdc++.h>
using namespace std;

struct Player{
	int teamID;
	int score;
	Player* nextP;
};

struct Team{
	int teamID;
	int diff;
	int playerN;
	Player* Plist;
};

Player Plist[100001];
Team Tlist[100001];

void init(int N)
{
	for(int i=1;i<=N;i++){
		Plist[i].teamID = i;
		Plist[i].score = 0;
		Plist[i].nextP = nullptr;

		Tlist[i].teamID = i;
		Tlist[i].diff = 0;
		Tlist[i].playerN = 1;
		Tlist[i].Plist = &Plist[i];
	}
}

void updateScore(int mWinnerID, int mLoserID, int mScore)
{
	Team* WinTeam = &Tlist[Plist[mWinnerID].teamID];
	Team* LoseTeam = &Tlist[Plist[mLoserID].teamID];

	WinTeam->diff += mScore;
	LoseTeam->diff -= mScore;
}

void unionTeam(int mPlayerA, int mPlayerB)
{
	Team* ATeam = &Tlist[Plist[mPlayerA].teamID];
	Team* BTeam = &Tlist[Plist[mPlayerB].teamID];

	if(ATeam->playerN > BTeam->playerN){
		Team* temp = ATeam;
		ATeam = BTeam;
		BTeam = temp;
	}

	Player* curr;
	curr = ATeam->Plist;
	while(curr->nextP!=nullptr){
		curr->score += (ATeam->diff - BTeam->diff);
		curr->teamID = BTeam->teamID;
		curr = curr->nextP;
	}
	curr->score += (ATeam->diff - BTeam->diff);
	curr->teamID = BTeam->teamID;
	curr->nextP = BTeam->Plist;

	BTeam->playerN += ATeam->playerN;
	BTeam->Plist = ATeam->Plist;

}

int getScore(int mID)
{
	int ret = Plist[mID].score + Tlist[Plist[mID].teamID].diff;
	return ret;
}

///////////////////////////////////////////////
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_UPDATE_SCORE 200
#define CMD_UNION_TEAM 300
#define CMD_GET_SCORE 400

static bool run()
{
	int queryCnt, cmd;
	int ans, res;
	bool okay = false;

	scanf("%d", &queryCnt);
	for (int i = 0; i < queryCnt; i++)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			int N;
			scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case CMD_UPDATE_SCORE:
			int mWinnerID, mLoserID, mScore;
			scanf("%d%d%d", &mWinnerID, &mLoserID, &mScore);
			updateScore(mWinnerID, mLoserID, mScore);
			break;
		case CMD_UNION_TEAM:
			int mPlayerA, mPlayerB;
			scanf("%d%d", &mPlayerA, &mPlayerB);
			unionTeam(mPlayerA, mPlayerB);
			break;
		case CMD_GET_SCORE:
			int mID;
			scanf("%d", &mID);
			res = getScore(mID);
			scanf("%d", &ans);
			if (ans != res)
			{
				okay = false;
			}
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d%d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}