#include<vector>
#include<iostream>
using std::vector,std::cout;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // if more than one 0 -> all zeros in output
				// cont zeros
				unsigned zeroCount{0};
				int nonZeroProduct{1}, zeroIndex{-1};
				for(unsigned i{0}; i<nums.size(); i++){
					if (nums[i] == 0) {
						zeroCount++;
						zeroIndex = i;
					} else {
						nonZeroProduct *= nums[i];
					}
				}
				if (zeroCount > 1 ) {
					// return all zeros
					vector<int> result(nums.size(),0);
					cout << "all zeroes";
					return result;
				} else if (zeroCount == 1){
					// return all zeros except in place of zero 
					//   there, return nonZeroProduct
					vector<int> result(nums.size(),0);
					result[zeroIndex] = nonZeroProduct;
					return result;
				} else {
					// get prefix postfix prod
					vector<int> result(nums.size(),0);
				}



        // if one zero -> 
        //  - get prod of all other than zero
				//  - prod bas 0 ke liye,
				//  - baaki sab 0
    }
};
