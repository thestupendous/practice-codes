#include<iostream>
#include<vector>
using std::vector,std::cout;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
			int toPlace{0}, zeroCount{0};
			for (int i{0};i<nums.size();i++){
				if (nums[i] != 0) {
					// place at suitable place;
					nums[toPlace++] = nums[i];
				} else {
					zeroCount++;
				}
			}
			
			// now to fill the remaining space with zeroes
			for (auto i{nums.size()-zeroCount};i<nums.size();i++) {
				nums[i] = 0;
			}

    }
};

int main() {
	vector<int> nums {1,0,3,7,0,0,2,10,0,0};
	vector<int> nums2 {0};
	Solution sol;
	sol.moveZeroes(nums);
	sol.moveZeroes(nums2);

	for (int i: nums) {
		cout << i << ",";
	}
	cout << '\n';

	for (int i: nums2) {
		cout << i << ",";
	}
	cout << '\n';

	return 0;
}
