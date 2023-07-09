#include <bits/stdc++.h>
using namespace std;

int k;
bool arr[10]; //0: >, 1: <
bool visited[10];
string ans[2] = {"0","0"};

void backtrack1(int count, string substr){
  if(count == k+1) {
    ans[0] = substr;
    return;
  }

  for(int i=0 ; i<=9 ; i++){
    if(visited[i] == true) continue;
    if(substr.length() != 0){
      if(arr[count-1] == 0){
        if(substr[count-1] < (i+'0')) continue;
      }
      else{
        if(substr[count-1] > (i+'0')) continue;
      }
    }

    string nextstr = substr;
    nextstr += (i+'0');
    visited[i] = true;
    backtrack1(count+1,nextstr);
    visited[i] = false;
  }

}

void backtrack2(int count, string substr){
  if(count == k+1) {
    ans[1] = substr;
    return;
  }

  for(int i=9 ; i>=0 ; i--){
    if(visited[i] == true) continue;
    if(substr.length() != 0){
      if(arr[count-1] == 0){
        if(substr[count-1] < (i+'0')) continue;
      }
      else{
        if(substr[count-1] > (i+'0')) continue;
      }
    }

    string nextstr = substr;
    nextstr += (i+'0');
    visited[i] = true;
    backtrack2(count+1,nextstr);
    visited[i] = false;
  }

}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> k;

  for(int i=0 ; i<k ; i++){
    char temp;
    cin >> temp;

    if(temp == '>')
      arr[i] = 0;
    else 
      arr[i] = 1;
  }

  backtrack1(0,"");
  backtrack2(0,"");

  cout<<ans[0]<<'\n'<<ans[1];

  return 0;
}