// looked at solution, after trying my own solutions many times
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int longestSubarray(vector<int>& nums) {
			int zeroCount{0};
			for(int v:nums) if(v==0) {
				zeroCount++;
			}
			if(zeroCount == 1) return nums.size()-1;
			cout<<"log\n";
			int left{0},right{0},ans{0};
			for(int currSize{0},zeroCount=0;right<nums.size();right++) {
				if(nums[right]==0) {
					zeroCount++;
				}
				if( zeroCount==2) {
					// remove all till last zero
					cout << "2 zero at left,right,currmax,ans: "
						<< left << ',' 
						<< right << ',' 
						<< currSize << ',' 
						<< ans << '\n' ;

					while(nums[left++]!=0){
						currSize--;
					}
					zeroCount--;
					currSize--;
					cout<< "now zeroCount : " << zeroCount << '\n';
				}
				
				currSize++;
				ans = max(ans,currSize);
			}
			return ans-1;
		}
};
int main() {
	cout<< "log: hi\n";
	Solution s;
	// vector<int> nums1{0,1,1,1,0,1,1,0,1};
	vector<int> nums1{0,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,1,1};
	cout << "[";
	for(int v:nums1) {
		cout << v << ',';
	}
	cout << "]\n";
	int ans1 = s.longestSubarray(nums1);
	cout << ans1 << '\n';

	return 0;
}

