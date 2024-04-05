#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1]; // 부분합 계산
    }

    int cnt = 0;
    for (int i = 1; i <= N-2; i++) {
        for (int j = i+1; j <= N-1; j++) {
            if (A[i] < A[j] - A[i] && A[j] - A[i] < A[N] - A[j]) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}