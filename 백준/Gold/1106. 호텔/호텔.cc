#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<pair<int, int>> ads(n);
	for(int i = 0; i < n; i++) {
		cin >> ads[i].first >> ads[i].second;
	}

	vector<int> dp(c + 101, INF);
	dp[0] = 0;

	for(int i = 0; i < n; i++) {
		int cost = ads[i].first;
		int val = ads[i].second;
		for(int j = val; j < c + 101; j++) {
			if (dp[j - val] != INF) {
				dp[j] = min(dp[j], dp[j - val] + cost);
			}
		}
	}

	int result = INF;
	for(int i = c; i < c + 101; i++) {
		result = min(result, dp[i]);
	}

	cout << result;

	return 0;
}