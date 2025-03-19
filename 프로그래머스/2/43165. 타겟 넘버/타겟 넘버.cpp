#include <string>
#include <vector>

using namespace std;

typedef struct Node {
    int num;
    int index;
} Node;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<Node> stack;
    
    stack.push_back(Node{numbers[0], 0});
    stack.push_back(Node{-numbers[0], 0});
    while(!stack.empty()){
        Node n = stack.back();
        stack.pop_back();
        if(n.index==numbers.size()-1){
            if(n.num == target) answer++;
            continue;
        }
        stack.push_back(Node{n.num+numbers[n.index+1], n.index+1});
        stack.push_back(Node{n.num-numbers[n.index+1], n.index+1});
    }
    
    return answer;
}