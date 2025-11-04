#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> set1;
				vector<int> result;
				result.push_back(-1);
				result.push_back(-1);

				// half count case
				// case when half of the target is present, other half is not
				int halfIndex1{-1},halfIndex2{-1};
				unsigned halfCount{0};
				if (target%2 == 0) {
						for (unsigned i{0};i<nums.size();i++) {
							if (nums[i]==target/2) {
								halfCount++;
								if(halfCount==1) halfIndex1=i;
								else if(halfCount==2) {
									halfIndex2=i;
									break;
								}
							}
						}
						if (halfCount==2) {
							// found the result
							result[0]=halfIndex1;
							result[1]=halfIndex2;
							return result;
						}
				}

				// fill set with complementary values
				for (int i{0};i<nums.size();i++) {
					set1.insert(target-nums[i]);
				}

				// if only one occurance of exact half, remove it from set
				if (halfCount==1) {
					set1.erase(nums[halfIndex1]);
				}
				// compare which index has complementary value in set
				int firstIndex{-1},secondIndex{-1};
				for (int i{0};i<nums.size();i++) {
					if ( set1.find(nums[i]) != set1.end() ) {
							// found one of them
						firstIndex = i;
						break;
					}
				}
				if (firstIndex == -1 && secondIndex == -1 ) {
					// pair is not present
				}

				// now find other one
				int secondValue=target-nums[firstIndex];
				for (int i{0};i<nums.size();i++) {
					if (nums[i]==secondValue) {
						secondIndex = i;
						break;
					}
				}

				if(firstIndex<secondIndex){
					result[0]=firstIndex;
					result[1]=secondIndex;
				} else{
					result[0]=secondIndex;
					result[1]=firstIndex;
				}
				return result;
    }
};

int main() {
	Solution sol;
#if 0
	vector<int> a{1,2,23,3,2,1,5,2,3,6,2,1,3,10};
	vector<int> ans = sol.twoSum(a,16);
	for(int i: ans) {
		cout << i << ", ";
	}
	cout << '\n';
#endif

	vector<int> a2{3,2,4};
	vector<int> ans2 = sol.twoSum(a2,6);
	for(int i: ans2) {
		cout << i << ", ";
	}
	cout << '\n';

}
