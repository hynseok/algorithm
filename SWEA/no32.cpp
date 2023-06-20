#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
/////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

list<int> ind[17576];
int makehashFlag = 0;
unordered_map<string, int> Hashmap;
int stringN;
string PrimeS;

void Insert(int Hidx, int Hdata){
    auto iter = ind[Hidx].begin();
    while(iter!=ind[Hidx].end()&&*iter<Hdata){
        iter++;
    }
	ind[Hidx].insert(iter,Hdata);
}

void Delete(int Hidx, int Hdata){
	auto iter = ind[Hidx].begin();
	while(iter!=ind[Hidx].end()){
		if(*iter==Hdata) {
			ind[Hidx].erase(iter++);
			break;
		}
		else ++iter;
	}
}

void init(int n, char init_string[]){
	PrimeS = init_string;
	stringN = n;
    if(makehashFlag == 0){
        int Hashnum=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    char S[3] = {'a','a','a'};
                    S[0] += i;
                    S[1] += j;
                    S[2] += k;
                    Hashmap[S] = Hashnum;
                    Hashnum++;
                }
            }
        }
        makehashFlag = 1;
    }

    for(int i=0;i<17576;i++){
        ind[i].clear();
    }

    for(int i=0;i<n-2;i++){
        char S[3];
        S[0] = init_string[i]; S[1] = init_string[i+1]; S[2] = init_string[i+2];
        ind[Hashmap[S]].push_back(i);
    }

}

int change(char string_A[], char string_B[]){
	int ret = 0;
    for(int i=0;i<stringN-2;i++){
		if(ind[Hashmap[string_A]].front() == i){
			vector<pair<string,int>> Sv; // str, idx
			for(int j=i-2;j<=i+2;j++){
				if(j<0)continue;
				char S[3]; S[0] = PrimeS[j]; S[1] = PrimeS[j+1]; S[2] = PrimeS[j+2];
				Sv.push_back({S,j});
			}
			for(int j=0;j<Sv.size();j++){
				Delete(Hashmap[Sv[j].first],Sv[j].second);
			}
			PrimeS[i] = string_B[0]; PrimeS[i+1] = string_B[1]; PrimeS[i+2] = string_B[2];

			Sv.clear();
			for(int j=i-2;j<=i+2;j++){
				if(j<0)continue;
				char S[3]; S[0] = j; S[1] = j+1; S[2] = j+2;
				Sv.push_back({S,j});
			}
			for(int j=0;j<Sv.size();j++){
				Insert(Hashmap[Sv[j].first],Sv[j].second);
			}
			ret++;
			i+=2;
		}
		
	}
	return ret;
}

void result(char ret[]){
	for(int i=0;i<stringN;i++){
		ret[i] = PrimeS[i];
	}
}


/////////////////////////////////////////////////////
static int seed = 5;  // seed can be changed
static int pseudo_rand(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

#define MAXL (50005)
#define DUMMY_LEN (5959)

static int init_string_len = 0, char_type = 0, query_cnt = 0;
static char dummy1[DUMMY_LEN];
static char init_string[MAXL];
static char dummy2[DUMMY_LEN];
static char result_string[MAXL];
static char dummy3[DUMMY_LEN];
static char user_ans_string[MAXL];
static char dummy4[DUMMY_LEN];
static char string_A[4], string_B[4];


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
	setbuf(stdout, NULL);
//	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int total_score = 0;
	for (int TC = 1; TC <= T; TC++) {
		int score = 100;
		scanf("%d%d%d%d", &seed, &init_string_len, &char_type, &query_cnt);
		
		for (int i = 0; i < init_string_len; i++)
		{
			init_string[i] = pseudo_rand() % char_type + 'a';
		}
		init_string[init_string_len] = '\0';

		init(init_string_len, init_string);

		string_A[3] = string_B[3] = '\0';
		for (int i = 0; i < query_cnt; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				string_A[k] = pseudo_rand() % char_type + 'a';
				string_B[k] = pseudo_rand() % char_type + 'a';
			}
			int user_ans = change(string_A, string_B);
			int ans;
			scanf("%d", &ans);

			if (ans != user_ans)
			{
				score = 0;
			}
			cout<<PrimeS<<' '<<user_ans<<'\n';
		}

		result(user_ans_string);
		scanf("%s", result_string);

		
		for (int i = 0; i < init_string_len; i++)
		{
			if (result_string[i] != user_ans_string[i])
			{
				score = 0;
				break;
			}
		}

		total_score += score;
		printf("#%d %d\n", TC, score);
	}
	printf("Total score : %d\n", total_score/T);

	return 0;
}