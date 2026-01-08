#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int a[26] = {0, };
  
  cin >> s;

  for(int i = 0; i < s.size(); i++) {
    int ascii = s[i];
    int idx = ascii - 97;
    a[idx]++;
  }

  for(int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }

  return 0;
}