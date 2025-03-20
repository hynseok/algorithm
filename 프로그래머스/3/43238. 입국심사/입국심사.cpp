#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
    sort(times.begin(), times.end());
    ll min = 1;
    ll max = n * (ll)times.back();
    
    while(min <= max) {
        ll mid = (min + max) / 2;
        ll tmp = 0;
        
        for(int i = 0; i < times.size(); i++) {
            tmp += mid / (ll)times[i];
        }
        
        if(tmp >= n) {
            max = mid - 1;
            answer = mid;
        } else {
            min = mid + 1;
        }
    }
    
    return answer;
}