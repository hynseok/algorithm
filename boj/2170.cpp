#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.first < b.first;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N;
  int sum = 0;
  int start, end;
  pair<int,int> temp;
  vector<pair<int,int> > points;

  cin >> N;

  for(int i=0;i<N;i++){
    cin >> temp.first >> temp.second;
    points.push_back(temp);
  }

  sort(points.begin(),points.end(), cmp);

  start = points[0].first;
  end = points[0].second;
  for(int i=1;i<points.size();i++){
    if(end < points[i].first){
      sum += (end - start);
      start = points[i].first;
      end = points[i].second;
    }
    else if(points[i].first <= end && points[i].second >= end){
      end = points[i].second;
    }
  }
  sum += (end-start);

  cout << sum;

  return 0;
}