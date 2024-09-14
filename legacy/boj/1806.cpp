#include <bits/stdc++.h>
#define FOR(i, N) for(int i=0; i<N; i++)
#define MAX_LEN 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[MAX_LEN];
	int N, S;
	int sum = 0;
	int len = 0;
	int ans = MAX_LEN;
	int tlen;
	int *start, *end;

	cin >> N >> S;
	
	FOR(i, N)
		cin >> arr[i];
	
	
	start = arr;
	end = arr;

	sum += *end;
	len = 1;

	while(start <= end) {
		if(sum >= S) {
			if(len < ans)
				ans = len;
			sum -= *start;
			start+=1;
			len--;
		}
		else if(end == (arr+N-1))
			break;
		else {
			end += 1;
			sum += *end;
			len++;		
		}
	}
	
	if(ans != MAX_LEN)
		cout << ans;
	else
		cout << 0;
}
