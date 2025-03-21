#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> pst;
    vector<int> sst;
    
    for(int i = progresses.size()-1; i >= 0; i--) {
        pst.push_back(progresses[i]);
        sst.push_back(speeds[i]);
    }
    
    int done = 0;
    while(!pst.empty()) {
        int tmp_done = 0;
        for(int i = 0; i < pst.size(); i++) {
            pst[i] += sst[i];
        }
        
        for(int i = pst.size()-1; i >= 0; i--) {
            if(pst[i] >= 100) {
                tmp_done++;
                pst.pop_back();
            } else {
                break;
            }
        }
        
        if(tmp_done != 0) {
            answer.push_back(tmp_done);
            done += tmp_done;
        }
    }
    
    return answer;
}