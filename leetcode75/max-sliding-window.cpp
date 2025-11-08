// learnt this from coursera dsa course
#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;
class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			deque<unsigned> dq; // dequeue of indices
			vector<int> result;

			for(unsigned i{0};i<k;i++) {
				while( !dq.empty() && nums[dq.back()]<nums[i] ){ 
					dq.pop_back();
				}
				dq.push_back(i);
			}
			result.push_back( nums[dq.front()] );

			int newItem;
			unsigned left=1;
			for (unsigned right(k); right < nums.size() ; left++,right++ ) {
				if ( dq.front() < left ) {
					dq.pop_front();
				}
				newItem = nums[right];
				while( !dq.empty() && nums[dq.back()]<newItem ){ 
					dq.pop_back();
				}
				dq.push_back(right);
				result.push_back( nums[dq.front()] );
			}

			//cout << "Result size bana: " << result.size() << '\n';
			return result;
		}
};

int main() {
	int n = 0;
	cin >> n;

	vector<int> A(n);
	for (size_t i = 0; i < n; ++i)
		cin >> A.at(i);

	int w = 0;
	cin >> w;

	// max_sliding_window_naive(A, w);
	vector<int> ans = maxSlidingWindow(A,w);
	// cout << "size: " << ans.size() << '\n';
	for(auto val: ans) {
		cout << val << ' ';
	}
	cout << '\n';
	return 0;
}

