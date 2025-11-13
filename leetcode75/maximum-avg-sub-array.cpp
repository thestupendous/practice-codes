#include <vector>
#include <iostream>
using namespace std;
#include <limits>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg{0},
							 res{std::numeric_limits<int>::min()};
        int sum{0},left{0},right{0};
        for(;right<k;right++) {
            sum += nums[right];
        }
        avg=static_cast<double>(sum)/k;
				res = max(res,avg);

				for(right=k,left=0;right<nums.size();left++,right++) {
					sum -= nums[left];
					sum += nums[right];
					avg=static_cast<double>(sum)/k;
					res = max(res,avg);
				}
				return res;
    }
};
