#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
	public:
		int equalPairs(vector<vector<int>>& grid) {
			cout << "xyes\n";
			int len(grid.size());
			map<vector<int>, int> arrMap;
			cout << "yyes\n";
			// cout << "zyes\n";
			int pairCount{0};

			// cout << "zyes\n";
			// columns
			for (int j{0}; j < len; j++) {
				vector<int> column(len);
				for (int i{0}; i < len; i++) {
					column[i] = grid[i][j];
				}
				arrMap[column] += 1;
			}

			// rows
			for (int i{0}; i < len; i++) {
				cout<<"for row: " << i+1 << '\n';
				int freq=arrMap[grid[i]];
				if(freq>0) {
					cout << "    match ["<<i+1<<"]\n";
					pairCount += freq;
				}
			}
			return pairCount;
		}
};
int main() {
	Solution s;
	vector<vector<int>> mat1;
#if 0
	// [[3,2,1],[1,7,6],[2,7,7]]
	mat1.push_back({3,2,1});
	mat1.push_back({1,7,6});
	mat1.push_back({2,7,7});
#endif
	// [[3,1,2,2],[1,4,4,4],[2,4,2,2],[2,5,2,2]]
	mat1.push_back({3,1,2,2});
	mat1.push_back({1,4,4,4});
	mat1.push_back({2,4,2,2});
	mat1.push_back({2,5,2,2});
	cout << s.equalPairs(mat1) << '\n';
	return 0;
}
