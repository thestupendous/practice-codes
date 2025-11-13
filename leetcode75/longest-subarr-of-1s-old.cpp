/*  WASTE ALGORITHM, NEED TO GET BETTER MINDSET AT SOLVING THIS
 *   currSize = 
 *      >  -10  -> matlab abhi tak koi 1 nahi mila
 * */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
		int longestSubarray(vector<int> &nums) {
			// yadi saare 1 hain to
			int zeroCount{0};
			for(int v: nums) { if(v==0) zeroCount++; }
			if (zeroCount==0 || zeroCount==1) return nums.size()-1;
			int left{-10};

			int currSize{0},maxSize{0},leftWala{0};
			for(int right{0};right<nums.size();right++) {
				// shuru vali sthiti
				// need to find first 1
				if (nums[right]==0 && left==-10) continue;
				if (nums[right]==1 && left==-10) {
					cout << "Log: i,curr size: " << right+1 << ',' << currSize << '\n';
					left=right;
					currSize=1;
					maxSize=max(maxSize,1);
					continue;
				}

				// pehla subarray (0 ke left wala)
				if (left!=-10 && nums[right]==1) {
					currSize++;
					cout << "Log: i,curr size: " << right+1 << ',' << currSize << '\n';
					maxSize = max(maxSize,currSize);
					left=right;
				}
				// pehla 0 mile to
				if (left!=-10 && nums[right]==0) {
					if (right+1 < nums.size() && nums[right+1]==1) {
						//cout << "Log: beech me 0, i: " << right+1 << 
						//	"\n   Current Max: " << currSize << "\n";
						cout << "Log: i,curr size: " << right+1 << ',' << currSize << '\n';
						if (leftWala > 0 ) {
							// phele se left wala hai to cur aur pehle ko jod ke 
							// naya max ban sakta hai
							maxSize = max(maxSize,currSize+leftWala);
							cout << "Log: combined " << leftWala<<','<<currSize << '\n';
						}

						leftWala = currSize;
						left = right+1;
						currSize = 0;
					} else if (right+1 < nums.size() && nums[right+1]==0) {
						if(leftWala!=0) {
							maxSize = max(maxSize,currSize+leftWala);
							cout << "Log: combined " << leftWala<<','<<currSize << '\n';
						}
							cout << "Log: MAX: " << maxSize << '\n';
						leftWala = 0;
						currSize = 0;
						left=-10;
					}
				}
			}
			// yadi last elemnt 1 tha
			if (leftWala!=0 && nums[nums.size()-1]==1) {
				maxSize = max(maxSize,currSize+leftWala);
							cout << "Log: MAX2: " << maxSize << '\n';
			} /*else {
					maxSize = max(maxSize,currSize);
					}
					*/
							cout << "Log: MAX3: " << maxSize << '\n';
			return maxSize;
		}
};

int main() {
	Solution s;

	// vector<int> nums1{0,1,1,1,0,1,1,0,1};
	// vector<int> nums1{1,1,0,1};
	// vector<int> nums1{1,1,0,0,1,1,1,0,1};
	// vector<int> nums1{0,1,1,1,0,0,1,1,0};
	vector<int> nums1{0,1,0,1,0};
	cout<<'[';
	for (int v: nums1) { cout<<v<<',';} cout<<"]\n";
	int ans = s.longestSubarray(nums1);
	cout << ans << '\n';

	return 0;
}
