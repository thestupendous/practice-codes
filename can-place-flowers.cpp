#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
		bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			int len(flowerbed.size());
			if(!len) return n>0 ? true : false;
			int count{0},prev{};
			for (int i{0};i<len;i++) {

				if (!prev && !flowerbed[i]) {
					if(i+1 < len && !flowerbed[i+1]) {
						prev=flowerbed[i];
						i++;
						count++;
						continue;
					} else if (i+1 >= len) {
						count++;
						break;
					}
				}

				prev=flowerbed[i];
			}
			return count>=n ;
		}
};
