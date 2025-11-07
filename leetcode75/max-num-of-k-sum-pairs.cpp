#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		int maxOperations(const vector<int>& nums, int k) {
			unordered_map<int, unsigned> map;
			int ans{0};

			for(int num: nums) {
				map[num]++;
			}

			int times;
			for(int num: nums) {
				if (num<1 || num>=k) continue;
				if ( ( k%2==0 && num != k/2 ) || (k%2!=0) ) {
					if ( map.find(k-num) != map.end() ) {
						// found one pair
						times = min(map[num],map[k-num]);
						ans += times;
						// cout << "got 1 : " << num << ", map[k-num]: " << map[k-num] << '\n';

						// now remove both entries from map
						map.erase(num);
						map.erase(k-num);

						// cout << ( ( map.find(k-num) != map.end() ) ? ("true") : ("false") )<< '\n';
					}
				}
				// when k/2 is present, it should be in multiples
				if (k%2==0 && num==k/2 && map.find(num) != map.end() && map[k/2]>=2 ) {
					times = map[num]/2;
					ans += times;
					// cout<< "k/2 found\n";
					map[num] -= 2*times;
				}
			}
			return ans;
		}

};
int main() {
	// 1,2,3,4 -> 5 -> 2
	Solution s;
#if 0
	vector<int> v2{1,2,3,4};
	int ans2 = s.maxOperations(v2,5);
	cout << ans2 << '\n';


	vector<int> v1{3,1,3,4,3};
	int ans = s.maxOperations(v1,6);
	cout << ans << '\n';

	vector<int> v3{2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2};
	int ans3 = s.maxOperations(v3,3);
	cout << ans3 << '\n';
#endif

	vector<int> v4{3,1,3,4,3};
	int ans4 = s.maxOperations(v4,6);
	cout << ans4 << '\n';

	return 0;
}
