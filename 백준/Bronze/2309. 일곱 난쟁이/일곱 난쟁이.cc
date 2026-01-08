#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a(9);

  for(int i = 0; i < 9; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  do {
    int ans = 0;
    for(int i = 0; i < 7; i++) {
      ans += a[i];
    }
    if(ans == 100) break;
  } while (next_permutation(a.begin(), a.end()));
  
  for(int i = 0; i < 7; i++) {
    cout << a[i] << "\n";
  }

  return 0;
}