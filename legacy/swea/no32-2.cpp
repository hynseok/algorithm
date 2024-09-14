#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
/////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

list<int> ind[17576];
int stringN;
string PrimeS;

int sHash(string S){
	int ret = 0;
	for(int i = 0; i < S.size(); i++){
        ret *= 26;
        ret += S[i] - 'a';
    }
    return ret;
}

void init(int n, char init_string[]){

    PrimeS = (string)init_string;
	stringN = PrimeS.size();

    for(int i=0;i<17576;i++){
        ind[i].clear();
	}
    if(n >= 3){
        int hash = 0;
        hash += (PrimeS[0] - 'a')*26;
        hash += (PrimeS[1] - 'a');
        for(int i = 2; i < stringN; i++){
            hash*=26;
            hash+=PrimeS[i]-'a';
            ind[hash].push_back(i-2);
            hash-=(PrimeS[i-2]-'a')*26*26;
        }
    }
}

int change(char string_A[], char string_B[]){
    int Ahash = sHash(string_A);
    int ret = 0;
    int idx;
    auto iter = ind[Ahash].begin();
    while(iter != ind[Ahash].end()){
        idx = *iter;
        ret++;
        for(int i=idx-2;i<=idx+2;i++){
            if(i<0) continue;
            if(i>=stringN-2) break;
            string temp;
            int hash = 0;
            for(int j = 0; j < 3; j++){
				hash *= 26;
                hash += PrimeS[i+j] -'a';
                temp.push_back(PrimeS[i+j]);
            }
            if(i==idx){
                iter = ind[hash].erase(find(ind[hash].begin(),ind[hash].end(),i));
            }
            else{
                ind[hash].erase(find(ind[hash].begin(),ind[hash].end(),i));
            } 
        }
        for(int i=idx;i<idx+3;i++){
            PrimeS[i] = string_B[i-idx];
        }
        
        for(int i=idx-2;i<=idx+2;i++){
            if(i<0) continue;
            if(i>=stringN-2) break;
            string temp;
			int hash = 0;
            for(int j = 0; j < 3; j++){
				hash *= 26;
                hash += PrimeS[i+j] -'a';
                temp.push_back(PrimeS[i+j]);
            }
            auto iter2 = ind[hash].begin();
            while(iter2 != ind[hash].end() && *iter2 < i){
                iter2++;
            }
            ind[hash].insert(iter2, i);
        }

        while(iter!=ind[Ahash].end()&&(*iter)<idx+3){
            iter++;
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