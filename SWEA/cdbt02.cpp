#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_ALLY 300
#define CMD_ATTACK 400
#define CMD_RECRUIT 500

/////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int F, Fnum;
int SolNum[26][26];
string MoName[26][26];
bool Ally[626][626];
bool Oppo[626][626];
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int dx[8] = {1,1,0,-1,-1,-1,0,1};

int Moidx(string moname){
    int ret = 0;
    for(int i=0;i<F;i++){
        for(int j=0;j<F;j++){
            if(MoName[i][j]==moname) return ret;

            ret++;
        }
    }

    return -1;
}

void init(int N, int mSoldier[25][25], char mMonarch[25][25][11])
{
    memset(SolNum,0,sizeof(SolNum));
    memset(MoName,0,sizeof(MoName));
    memset(Ally,0,sizeof(Ally));
    memset(Oppo,0,sizeof(Oppo));

    F = N;
    Fnum = N*N;

    for(int i=0;i<F;i++){
        for(int j=0;j<F;j++){
            SolNum[i][j] = mSoldier[i][j];
            MoName[i][j] = mMonarch[i][j];
        }
    }

}

void destroy()
{

}

int ally(char mMonarchA[11], char mMonarchB[11])
{	
    if(mMonarchA == mMonarchB) return -1;

    int Aidx = Moidx(mMonarchA);
    int Bidx = Moidx(mMonarchB);

    if(Ally[Aidx][Bidx]==true||Ally[Bidx][Aidx]==true)return -1;

    int flag = 1;
    for(int i=0;i<Fnum;i++){
        if(Ally[Aidx][i]==true){
            if(Oppo[Bidx][i]==true) flag = 0;
        }
        if(Ally[Bidx][i]==true){
            if(Oppo[Aidx][i]==true) flag = 0;
        }
    }
    if(flag==0) return -2;
    else
    {
        for(int i=0;i<Fnum;i++){
            if(Ally[Aidx][i]==true){
                Ally[Bidx][i] = true;
                Ally[i][Bidx] = true;
            }
            if(Ally[Bidx][i]==true){
                Ally[Aidx][i] = true;
                Ally[i][Aidx] = true;
            }
        }
    }
    Ally[Aidx][Bidx] = true;
    Ally[Bidx][Aidx] = true;

    return 1;
}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
	int Aidx = Moidx(mMonarchA);
    int Ay = Aidx/F; int Ax = Aidx%F;
    int Bidx = Moidx(mMonarchB);
    int By = Bidx/F; int Bx = Bidx%F;

    if(Ally[Aidx][Bidx]==true) return -1;
    
    int AllyFlag = 0;
    for(int i=0;i<8;i++){
        int ny = By + dy[i];
        int nx = Bx + dx[i];
        if(ny<0||ny>=F||nx<0||nx>=F) continue;
        int Nidx = ny*F + nx;
        if(Nidx==Aidx) AllyFlag = 1;
        if(Ally[Aidx][Nidx]==true) AllyFlag = 1;
    }
    if(AllyFlag==0) return -2;

    for(int i=0;i<Fnum;i++){
        if(Ally[Aidx][i]==true) {
            Oppo[Bidx][i] = true;
            Oppo[i][Bidx] = true;
        }
        if(Ally[Bidx][i]==true) {
            Oppo[Aidx][i] = true;
            Oppo[i][Aidx] = true;
        }
    }
    Oppo[Aidx][Bidx] = true;
    Oppo[Bidx][Aidx] = true;

    int AttackN=0;
    for(int i=0;i<8;i++){
        int ny = By + dy[i];
        int nx = Bx + dx[i];
        if(ny<0||ny>=F||nx<0||nx>=F) continue;
        int Nidx = ny*F + nx;
        if(Nidx==Aidx){
            AttackN += SolNum[ny][nx] / 2;
            SolNum[ny][nx] -= (SolNum[ny][nx]/2);
        }
        else if(Ally[Aidx][Nidx]==true){
            AttackN += SolNum[ny][nx] / 2;
            SolNum[ny][nx] -= (SolNum[ny][nx]/2);
        }
        else if(Ally[Bidx][Nidx]==true){
            SolNum[By][Bx] += SolNum[ny][nx] / 2;
            SolNum[ny][nx] -= (SolNum[ny][nx]/2);
        }
    }

    int ret;
    if(AttackN>SolNum[By][Bx]){
        for(int i=0;i<Fnum;i++){
            Ally[Bidx][i] = false;
            Oppo[Bidx][i] = false;
        }
        MoName[By][Bx] = mGeneral;
        ally(mMonarchA,mGeneral);
        for(int i=0;i<Fnum;i++){
            if(Oppo[Aidx][i]==true)Oppo[Bidx][i] = true;
        }
        ret = 1;
    }
    else{
        ret = 0;
    }
    return ret;
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
    int ret = 0;
    int midx = Moidx(mMonarch);
    int my = midx/F;
    int mx = midx%F;

	if(mOption==0){
        SolNum[my][mx] += mNum;
        ret += SolNum[my][mx];
    }
    else if(mOption==1){
        for(int i=0;i<Fnum;i++){
            if(Ally[midx][i]==true){
                int iy = i/F;
                int ix = i%F;

                SolNum[iy][ix] += mNum;
                ret += SolNum[iy][ix];
            }
        }
        SolNum[my][mx] += mNum;
        ret += SolNum[my][mx];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////

#define MAX_N 25
#define MAX_L 10

static int Sol[MAX_N][MAX_N];
static char General[MAX_N][MAX_N][MAX_L + 1];

static int run()
{
	int isOK = 0;

	int N;
	int cmd;
	int result;
	int check;

	int mN;
	char mMonarchA[11];
	char mMonarchB[11];
	char mGeneral[11];
	int mOption;
	int num;

	scanf("%d", &N);

	for (int c = 0; c < N; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &mN);
			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%d", &Sol[j][i]);

			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%s", General[j][i]);

			init(mN, Sol, General);
			isOK = 1;
			break;

		case CMD_ALLY:
			scanf("%s %s", mMonarchA, mMonarchB);
			result = ally(mMonarchA, mMonarchB);
            printf("%d",result);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_ATTACK:
			scanf("%s %s %s", mMonarchA, mMonarchB, mGeneral);
			result = attack(mMonarchA, mMonarchB, mGeneral);
            printf("%d",result);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_RECRUIT:
			scanf("%s %d %d", mMonarchA, &num, &mOption);
			result = recruit(mMonarchA, num, mOption);
            printf("%d",result);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}

	destroy();

	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}