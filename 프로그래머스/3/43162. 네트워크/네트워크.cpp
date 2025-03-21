#include <string>
#include <vector>
#include <stack>

using namespace std;

bool visited[201] = {0, };

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;    
    
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            s.push(i);
            answer++;
            
            while(!s.empty()) {
                int node = s.top();
                s.pop();
                visited[node] = true;
                
                for(int i = 0; i < n; i++) {
                    if(computers[node][i] && !visited[i]){
                        s.push(i);
                    }
                }
            }
        }
    }
    
    
    return answer;
    
}