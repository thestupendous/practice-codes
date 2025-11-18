#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int longestOnes(vector<int>& nums, int k) {
			int oneCount{0},zeroCount{0};
			for (int v : nums)
				if (v == 0) {
					zeroCount++;
				}else{
					oneCount++;
				}
        if (!oneCount) return k>0 ? k : 0;
			if (zeroCount <= k)
				return nums.size();
			//cout << "log\n";
			int left{0}, right{0}, ans{0};
			for (int  zeroCount = 0; right < nums.size(); right++) {
				if (nums[right] == 0) {
					zeroCount++;
				}
				
				while(zeroCount > k) {
					if(nums[left]==0) zeroCount--;
					left++;
				}

					//cout << "now zeroCount : " << zeroCount << '\n';

				ans = max(ans,1+right-left);
				cout<< "updated at r,l,ans: " <<
					right<<','<<
					right<<','<<
					ans<<'\n';
			}
			return ans;
		}
};
int main() {
	cout<< "log: hi\n";
	Solution s;
	// vector<int> nums1{0,1,1,1,0,1,1,0,1};
	// vector<int> nums1{0,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1,1};
	vector<int> nums1{0,0,0,1};
	cout << "[";
	for(int v:nums1) {
		cout << v << ',';
	}
	cout << "]\n";
	int ans1 = s.longestOnes(nums1,4);
	cout << ans1 << '\n';

	return 0;
}

