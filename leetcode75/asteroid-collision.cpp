#include <atomic>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
unsigned absv(const int &x) { 
	return x > 0 ? (static_cast<unsigned>(x)) 
	: (static_cast<unsigned>(-x)); 
}
void swaps(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
			stack<int> st;

			for(auto asteroid: asteroids) {
				if (asteroid > 0) {
					st.push(asteroid);
				} else if (asteroid < 0) {
					if ( st.empty() || st.top() < 0 ) {
						st.push(asteroid);
					} else if (st.top() > 0) {
						bool toPush=false;
						while ( !st.empty() && st.top() > 0) {
							if ( !st.empty() && absv(st.top()) > absv(asteroid) ) {
								// -ve vale ko phod do
								toPush=false;
								break;
							} else if ( !st.empty() && absv(st.top()) < absv(asteroid) ) {
								toPush = true;
								// +ve vale ko phod do
								st.pop();
							} else { // both of equal magnitude
								// dono ko phod do
								toPush=false;
								st.pop();
								break;
							}
						}
						if (toPush) st.push(asteroid);
					}
				}
			}
      
			// now to retrieve the elements from stack
			vector<int> result(st.size());
			unsigned resultI{0};
			while ( !st.empty() ) {
				result[resultI++] = st.top();
				st.pop();
			}
			// now reverse the result vector/array
			for(resultI=0; resultI < result.size()/2; resultI++){
				// cout << "swapping " << result[resultI] << 
				// 	',' << result[result.size()-1-resultI] << '\n';
				swaps(result[resultI],result[result.size()-1-resultI]);
			}
			return result;
    }
};

int main() {
	Solution s;
#if 0
	vector<int> vec1{-7,-3,7,5,3,-4,-6};
	vector<int> result {s.asteroidCollision(vec1)};
	cout << "[";
	for (auto val: result) {
		cout << val << ',';
	}
	cout << "]\n";
#endif

	vector<int> vec2{3,5,-6,2,-1,4};
	vector<int> result2 {s.asteroidCollision(vec2)};
	cout << "[";
	for (auto val: result2) {
		cout << val << ',';
	}
	cout << "]\n";

	vector<int> vec3{-2,-2,1,-2};
	vector<int> result3 {s.asteroidCollision(vec3)};
	cout << "[";
	for (auto val: result3) {
		cout << val << ',';
	}
	cout << "]\n";


	return 0;
}
