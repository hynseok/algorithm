#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash_map;
    
    for(int i = 0; i < participant.size(); i++) {
        if(hash_map.find(participant[i]) == hash_map.end()) {
            hash_map.insert({participant[i], 1});
        } else {
            hash_map[participant[i]]++;
        }
    }
    
    for(int i = 0; i < completion.size(); i++) {
        hash_map[completion[i]]--;
    }
    
    for(int i = 0; i < participant.size(); i++) {
        if(hash_map[participant[i]] > 0) {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}