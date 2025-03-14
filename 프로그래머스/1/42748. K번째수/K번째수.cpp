#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++) {
        vector<int> cmd = commands[i];
        
        int start = cmd[0] - 1;
        int end = cmd[1];
        int j = cmd[2] - 1;
        
        vector<int> v = vector<int>(array.begin() + start, array.begin() + end);
        
        sort(v.begin(), v.end());
        
        answer.push_back(v[j]);
    }
    
    return answer;
}