#include <bits/stdc++.h>
#define MAX_SOL 100001
#define MAX_NUM 2000000000

using namespace std;

int arr[MAX_SOL];
int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int *start, *end;
	int sum = MAX_NUM; 
	int ans1, ans2;

	cin >> N;
	
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}

	start = arr;
	end = arr + N - 1;
	
	while(start < end) {
		int tsum = *start + *end;
		if(abs(tsum) <= abs(sum)){
			sum = tsum;
			ans1 = *start;
			ans2 = *end;
		}
		if(tsum<0) 
			start++;
		else
			end--;
	}

	cout << ans1 << " " << ans2;

}
