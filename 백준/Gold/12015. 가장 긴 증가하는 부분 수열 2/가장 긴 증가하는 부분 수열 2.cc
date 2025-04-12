#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
vector<int> cand;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  cin >> arr[0];
  cand.push_back(arr[0]);
  for(int i = 1; i < n; i++) {
    cin >> arr[i];
    if(cand.back() < arr[i]) {
      cand.push_back(arr[i]);
    } else {
      int idx = lower_bound(cand.begin(), cand.end(), arr[i]) - cand.begin();
      cand[idx] = arr[i];
    }
  }
  cout << cand.size();
}
