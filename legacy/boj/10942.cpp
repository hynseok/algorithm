#include <bits/stdc++.h>
#define MAX_NUM 2001

using namespace std;

int N, M;
int arr[MAX_NUM];
bool is_palindrom_arr[MAX_NUM][MAX_NUM];

bool is_palindrom(int start, int end) {
  if(start == end) {
    return true;
  }
  else if(end - start == 1) {
    if(arr[start] == arr[end]) return true;
  }
  else {
    if(is_palindrom_arr[start+1][end-1]) 
      if(arr[start] == arr[end]) return true;
  }
    
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N - i; j++) {
      if(is_palindrom(j,j+i)) is_palindrom_arr[j][j+i] = true;
    }
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    cout << (is_palindrom_arr[start-1][end-1] ? 1 : 0) << "\n";
  }

}