#include <iostream>
#include <vector>

using namespace std;

vector<int> score;

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  int n;
  int k;

  cin >> n >> k;

  // for index 0
  score.push_back(0);

  for(int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;

    score.push_back(score[i-1] + temp);
  }

  cout << fixed;
  cout.precision(2);
  for(int i = 0; i < k; i++) {
    int a, b;
    double sum;
    cin >> a >> b;

    sum = score[b] - score[a-1];
    cout << sum / (b - a + 1) << "\n";
  }

  return 0;
}