#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum_map[501][501] = {0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    sum_map[0][0] = triangle[0][0];
    
    
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            if(j == 0) {
                sum_map[i][j] = sum_map[i-1][0] + triangle[i][j]; 
            } else if(j == triangle[i].size()-1) {
                sum_map[i][j] = sum_map[i-1][j-1] + triangle[i][j];
            } else {
                sum_map[i][j] = max(sum_map[i-1][j-1], sum_map[i-1][j]) + triangle[i][j];
            }   
        }
    }
    
    for(int i = 0; i < triangle[triangle.size()-1].size(); i++) {
        answer = max(answer, sum_map[triangle.size()-1][i]);
    }
    return answer;
}