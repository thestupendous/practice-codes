#include<iostream>
#include<vector>

#include <chrono>
#include <thread>
using namespace std;
struct MaxSet {
	int leftIndexi,rightIndexi;
	int maxWater;
	MaxSet(): leftIndexi(-1), rightIndexi(-1), maxWater(0)
	{}
};
class Solution {
	public:
		// brute force solution, may not be accepted
		MaxSet maxAreaBruteForce(vector<int>& height) {
			// gett all subarray
			MaxSet res;
			int maxW{0},water;
			for (int i{0}; i<height.size(); i++ ) {
				for (int j{i}; j<height.size(); j++) {
					// i to j is a subarray
					// cout << "found subarray: " << i << " to " << j << '\n';
					// extractSubArray(arr,i,j);
					water = min(height[i],height[j]) * (j-i);
					// cout << "water is " << water << "\n";
					if (water > res.maxWater) {
						res.leftIndexi = i;
						res.rightIndexi = j;
						res.maxWater = water;
					}
				}
			}
			return res;
		}

		MaxSet maxArea(vector<int>& height) {
			MaxSet res;
			if (height.size()<=1) {
				res.maxWater=0;
				return res;
			} else if (height.size() == 2) {
				res.maxWater = min(height[0],height[1]);
				res.leftIndexi = 0;
				res.rightIndexi = 1;
			}

			// set initial container 
			// with leftmost and rightmost walls
			res.leftIndexi = 0;
			res.rightIndexi = height.size()-1;
			res.maxWater = (res.rightIndexi-res.leftIndexi) * 
				(min(height[res.leftIndexi],height[res.rightIndexi])) ; 
			cout << "Initial water: " << res.maxWater << "\n";

			int leftIndex{res.leftIndexi}, rightIndex{res.rightIndexi}, 
					water{res.maxWater};
			bool leftIsMin;
			while (leftIndex < rightIndex) {
				cout << "left,right " << leftIndex << ',' << rightIndex << '\n';
				cout << "ans :  " << res.leftIndexi << ',' << res.rightIndexi 
					<< ',' << res.maxWater << '\n';
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

#if 1
				int curr;
				// find out lesser side
				if (height[leftIndex]<=height[rightIndex]) 
					leftIsMin = true;
				else leftIsMin = false;
				if(leftIsMin) {
					curr = leftIndex+1;
					if(leftIndex+1 < rightIndex /*&& height[leftIndex+1]>height[leftIndex]*/) {
						water = (rightIndex-leftIndex-1) *
							min(height[rightIndex],height[leftIndex+1]);
						if (water>res.maxWater) {
							cout << "Updating1\n";
							res.maxWater=water;
							res.leftIndexi = leftIndex+1;
							res.rightIndexi = rightIndex;
						}
							leftIndex++;
					} else break;
				} else {
					curr = rightIndex-1;
					if(rightIndex-1 > leftIndex /*&& height[rightIndex-1]>height[rightIndex]*/) {
						water = (rightIndex-leftIndex-1) *
							min(height[rightIndex-1],height[leftIndex]);
						if (water>res.maxWater) {
							cout << "Updating\n";
							res.maxWater=water;
							res.leftIndexi = leftIndex;
							res.rightIndexi = rightIndex-1;
						}
							rightIndex--;
					} else break;
				}
#endif
			}
			return res;
		}
};

int main() {
	Solution sol;
	vector<int> arr{2,8,6,2,5,4,8,3,7};
	MaxSet res { sol.maxArea(arr) };
	cout << res.leftIndexi << ',' << res.rightIndexi << ','
		<< res.maxWater << '\n';
	vector<int> arr2{4,3,2,1,4};
	MaxSet res2 { sol.maxArea(arr2) };
	cout << res2.leftIndexi << ',' << res2.rightIndexi << ','
		<< res2.maxWater << '\n';
	return 0;
}
