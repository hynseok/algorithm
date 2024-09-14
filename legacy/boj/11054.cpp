#include <bits/stdc++.h>
using namespace std;

int N;
int seq[1001];
int incr[1001] = {1, };
int decr[1001] = {1, };

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  
  for(int i = 0; i < N; i++) {
    cin >> seq[i];
    incr[i] = 1;
    decr[i] = 1;
  }
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      if(seq[i] > seq[j]) {
        incr[i] = max(incr[j] + 1, incr[i]);
      }
    }
  }

  for(int i = N - 1; i >= 0; i--) {
    for(int j = N - 1 ; j > i; j--) {
      if(seq[i] > seq[j]) {
        decr[i] = max(decr[j] + 1, decr[i]);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, incr[i] + decr[i] - 1);
  }

  cout << ans << "\n";

  return 0;
}