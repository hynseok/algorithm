#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int stu[31] = {0, };
    for(int i = 0; i < lost.size(); i++) {
        stu[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++) {
        stu[reserve[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(stu[i] < 0) {
            if(stu[i-1] > 0) {
                stu[i-1]--;
                stu[i]++;
            } else if(stu[i+1] > 0) {
                stu[i+1]--;
                stu[i]++;
            }
        }
        if(stu[i]>=0) answer++;
    }
    
    return answer;
}