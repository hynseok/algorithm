#include <bits/stdc++.h>
using namespace std;

int visited[100001] = {0, };
int N, K;

int bfs(){

  deque<int> dq;
  dq.push_back(N);
  visited[N] = 1;

  while(!dq.empty()){
    int now = dq.front();
    dq.pop_front();

    if(now == K) return visited[K] - 1;

    int next;
    next = now * 2;
    if(next <= 100000 && visited[next] == 0){
      visited[next] = visited[now];
      dq.push_front(next);
    }

    next = now - 1;
    if(next >= 0 && visited[next] == 0){
      visited[next] = visited[now]+1;
      dq.push_back(next);
    }
    
    next = now + 1;
    if(next <= 100000 && visited[next] == 0 ){
      visited[next] = visited[now]+1;
      dq.push_back(next);
    }

    
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> K;

  cout<<bfs();
  return 0;
}