/*
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(const vector<int>& nums) {
        vector<int> suff(nums.size());
        vector<int> pref(nums.size());

        // calculate suffix array
        suff[nums.size()-1] = nums[nums.size()-1];
        for(int i{static_cast<int>(nums.size()-2)};i>=0;i--) {
            suff[i] = suff[i+1]+nums[i];
        }

        pref[0] = nums[0];
        for(int i{1};i<nums.size();i++) {
            pref[i] = pref[i-1]+nums[i];
        }

        int left,right,pivot{-1};
        for(int i{0};i<nums.size();i++) {
            left = i-1>=0 ? pref[i-1] : 0 ;
            right = i+1<nums.size() ? suff[i+1] : 0;
            if (left == right) {
                pivot = i;
                break;
            }
        }

        if (pivot!=-1) return pivot;
        return -1;
    }
};

int main() {
	Solution s;
#if 0
	vector<int> v{1,7,3,6,5,6};
  int ans = s.pivotIndex(v);
	cout << ans << '\n';
#endif
	vector<int> v2{-1,-1,-1,-1,0,1};
  int ans2 = s.pivotIndex(v2);
	cout << ans2 << '\n';
	return 0;
}
