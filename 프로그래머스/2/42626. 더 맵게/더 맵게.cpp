#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int f, s, mix;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(1) {
        if(pq.top() >= K) {
            break;
        }
        if(pq.size() == 1) {
            answer = -1;
            break;
        } 
        
        f = pq.top(); pq.pop();
        s = pq.top(); pq.pop();
        mix = f + s*2;
        pq.push(mix);
        answer++;
    }
    
    return answer;
}