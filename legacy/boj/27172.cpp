#include <bits/stdc++.h>

using namespace std;

int N;
int num[100001];
int score[1000001];
int card[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> num[i];
		card[num[i]] = 1;
	}

	for(int i=0; i<N; i++){
		for(int j=num[i]*2; j<1000001; j+=num[i]){
			if(card[j]) {
				score[num[i]]++;
				score[j]--;
			}
		}
	}

	for(int i=0; i<N; i++) {
		cout << score[num[i]] << " ";
	}

}
