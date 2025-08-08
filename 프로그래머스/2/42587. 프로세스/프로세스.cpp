#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!pq.empty()) {
        pair<int, int> cand;
        cand = q.front();
        q.pop();
        
        if(cand.second != pq.top()) {
            q.push(cand);
        } else {
            if(cand.first == location) {
                break;
            } else {
                pq.pop();
                answer++;
            }
        }
    }
    return answer;
}