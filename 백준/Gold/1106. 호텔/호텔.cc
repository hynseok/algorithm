#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, n;
vector<pair<int, int> > ads(1001);
vector<int> dp(100001);

int main() {
	cin >> c >> n;

	for(int i = 0; i < n; i++) {
		cin >> ads[i].first >> ads[i].second;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= 100000; j++) {
			int cost = ads[i].first;
			int val = ads[i].second;
			if(j - cost >= 0) {
				dp[j] = max(dp[j], dp[j - cost] + val);
			}
		}
	}

	cout << lower_bound(dp.begin(), dp.end(), c) - dp.begin();

	return 0;
}