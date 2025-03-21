#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int seq1[5] = {1, 2, 3, 4, 5};
    int seq2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int seq3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int correct[4] = {0, };

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == seq1[i%5])
            correct[1]++;
        if(answers[i] == seq2[i%8])
            correct[2]++;
        if(answers[i] == seq3[i%10])
            correct[3]++;
    }
    
    int max = 0;
    for(int i = 1; i <= 3; i++) {
        if(max < correct[i])
            max = correct[i];
    }
    for(int i = 1; i <= 3; i++) {
        if(correct[i] == max) 
            answer.push_back(i);
    }
    
    return answer;
}