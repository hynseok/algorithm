#include <bits/stdc++.h>
using namespace std;

struct postlist{
    int pid=0;
    int uid=0;
    int like=0;
    int timestamp=0;
};

struct compare{
    bool operator()(const postlist a, const postlist b){
        if(a.like==b.like){
            return a.timestamp<b.timestamp;
        }
        return a.like<b.like;
    }

};

struct compare2{
    bool operator()(const postlist a, const postlist b){
        return a.timestamp<b.timestamp;
    }
};

vector<postlist> PostList;
int isFollow[1001][1001];
void init(int N)
{
    PostList.clear();
    memset(isFollow,0,sizeof(isFollow));
    return;
}

void follow(int uID1, int uID2, int timestamp)
{
    isFollow[uID1][uID2] = 1;
    return;
}

void makePost(int uID, int pID, int timestamp)
{
    postlist temp;
    temp.pid = pID;
    temp.uid = uID;
    temp.timestamp = timestamp;
    temp.like = 0;
    PostList.push_back(temp);
    return;
}

void like(int pID, int timestamp)
{
    PostList[pID-1].like += 1;
    return;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
    memset(pIDList,0,sizeof(int)*10);
    priority_queue<postlist,vector<postlist>,compare> pq;
    priority_queue<postlist,vector<postlist>,compare2> pq2;
    for(int i=0;i<PostList.size();i++){
        if(isFollow[uID][PostList[i].uid]==1||uID==PostList[i].uid){
            if(timestamp-PostList[i].timestamp<=1000) pq.push(PostList[i]);
            else{
                pq2.push(PostList[i]);
            }
        }
    }

    int flag = 0;
    int size1 = pq.size();
    int size2 = pq2.size();
    for(int i=0;i<size1;i++){
        postlist temp;
        temp = pq.top();
        pq.pop();
        pIDList[i] = temp.pid;
        flag++;
        if(flag==10)break;
    }
    if(flag<9){
        for(int i=0;i<size2;i++){
            postlist temp;
            temp = pq2.top();
            pq2.pop();
            pIDList[flag] = temp.pid;
            flag++;
            if(flag==10)break;
        }
    }
    return;
}

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>


static int mSeed;
static int pseudo_rand(void)
{
	mSeed = mSeed * 431345 + 2531999;
	return mSeed & 0x7FFFFFFF;
}

static int follow_status[1005][1005];
static int answer_score;
static int n; // n >= 2 && n <= 1000
static int end_timestamp;
static int follow_ratio; // follow_ratio >= 1 && follow_ratio <= 10000
static int make_ratio; // make_ratio >= 1 && make_ratio <= 10000
static int like_ratio; // like_ratio >= 1 && like_ratio <= 10000
static int get_feed_ratio; // get_feed_ratio >= 1 && get_feed_ratio <= 10000
static int post_arr[200000];
static int total_post_cnt;
static int min_post_cnt;

static bool run()
{
	int uId1, uId2, pId, pIdList[10], ans_pIdList[10], rand_val;
	bool ret = true;

	scanf("%d%d%d%d%d%d%d", &mSeed, &n, &end_timestamp, &follow_ratio, &make_ratio, &like_ratio, &get_feed_ratio);
	init(n);

	for (int uId1 = 1; uId1 <= n; uId1++)
	{
		follow_status[uId1][uId1] = 1;
		int m = n / 10 + 1;
		if (m > 10)
			m = 10;
		for (int i = 0; i < m; i++)
		{
			uId2 = uId1;
			while (follow_status[uId1][uId2] == 1)
			{
				uId2 = pseudo_rand() % n + 1;
			}
			follow(uId1, uId2, 1);
			follow_status[uId1][uId2] = 1;
		}
	}
	min_post_cnt = total_post_cnt = 1;

	for (int timestamp = 1; timestamp <= end_timestamp; timestamp++)
	{
		rand_val = pseudo_rand() % 10000;
		if (rand_val < follow_ratio)
		{
			uId1 = pseudo_rand() % n + 1;
			uId2 = pseudo_rand() % n + 1;
			int lim = 0;
			while (follow_status[uId1][uId2] == 1 || uId1 == uId2)
			{
				uId2 = pseudo_rand() % n + 1;
				lim++;
				if (lim >= 5)
					break;
			}
			if (follow_status[uId1][uId2] == 0)
			{
				follow(uId1, uId2, timestamp);
				follow_status[uId1][uId2] = 1;
			}
		}
		rand_val = pseudo_rand() % 10000;

		if (rand_val < make_ratio)
		{
			uId1 = pseudo_rand() % n + 1;
			post_arr[total_post_cnt] = timestamp;

			makePost(uId1, total_post_cnt, timestamp);
			total_post_cnt += 1;
		}

		rand_val = pseudo_rand() % 10000;

		if (rand_val < like_ratio && total_post_cnt - min_post_cnt > 0)
		{
			while (post_arr[min_post_cnt] < timestamp - 1000 && min_post_cnt < total_post_cnt)
				min_post_cnt++;

			if (total_post_cnt != min_post_cnt)
			{
				pId = pseudo_rand() % (total_post_cnt - min_post_cnt) + min_post_cnt;
				like(pId, timestamp);
			}
		}

		rand_val = pseudo_rand() % 10000;
		if (rand_val < get_feed_ratio && total_post_cnt > 0)
		{
			uId1 = pseudo_rand() % n + 1;
			getFeed(uId1, timestamp, pIdList);

			for (int i = 0; i < 10; i++)
			{
				scanf("%d", ans_pIdList + i);
			}

			for (int i = 0; i < 10; i++)
			{
				if (ans_pIdList[i] == 0)
					break;
                cout<<pIdList[i]<<' ';
            	if (ans_pIdList[i] != pIdList[i])
				{
					ret = false;
				}
			}
            cout<<'\n';
		}
	}

	return ret;
}

int main()
{
//	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int tc;
	scanf("%d%d", &tc, &answer_score);

	for (int t = 1; t <= tc; t++)
	{
		int score;
		for (int i = 0; i < 1005; i++)
			for (int j = 0; j < 1005; j++)
				follow_status[i][j] = 0;

		if (run())
			score = answer_score;
		else
			score = 0;

		printf("#%d %d\n", t, score);
	}
	return 0;
}