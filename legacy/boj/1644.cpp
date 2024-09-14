#include <bits/stdc++.h>

using namespace std;

bool *prime_check;
int *prime_arr;

int main() 
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int N, i, j, nprime = 0;
  int start = 0, end = 0, sum = 0, ans = 0;

  cin >> N;

  prime_check = (bool *)malloc((N+1) * sizeof(bool));
  memset((void *)prime_check, true, ((N+1) * sizeof(bool)));
  
  for(i = 2; i * i <= N; i++){
    if(prime_check[i]){
      for(j = i * i; j <= N; j += i){
        prime_check[j] = false;
      }
    }
  }
  for(i = 2; i <= N; i++)
    if(prime_check[i]) nprime++;

  prime_arr = (int*)malloc((nprime+1) * sizeof(int));

  j = 0;
  for(i = 2; i <= N; i++){
    if(prime_check[i]){
      prime_arr[j] = i;
      j++;
    }
  }

  while(end <= nprime){
    if(sum >= N){
      sum -= prime_arr[start++];
    }
    if(sum < N){
      sum += prime_arr[end++];
    }
    if(sum == N)
      ans++;
  } 

  cout << ans;

  free((void *)prime_check);
  free((void *)prime_arr);

  return 0;
}