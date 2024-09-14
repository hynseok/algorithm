#include <bits/stdc++.h>

using namespace std;

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }    
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};

int arr[5000001];
custom_priority_queue<int> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, L;
	int t;	
	cin	>> N >> L;

	for(int i=0; i<N; i++) {
		if(i>=L)
			q.remove(-arr[i-L]);
		
		cin >> t;
		arr[i] = t;
		q.push(-t);
		cout << -q.top() << " ";
	}
}
