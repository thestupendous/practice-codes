#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
	return c=='a' ||
		c=='e' ||
		c=='i' ||
		c=='o' ||
		c=='u' ? (true) : (false) ;
}
class Solution {
	public:
		int maxVowels(string s, int k) {
			if (s.size()==1 && k==1) {
				if (isVowel(s[0])) return 1;
				else return 0;
			}
			int currCount{0},maxCount{0};

			//fill up window
			for(int curr{0}; curr<k; curr++) {
				if (isVowel(s[curr])) {
					currCount++;
				}
			}
			maxCount = currCount;

			int left{0};
			for (int right{k}; right<s.size() ; right++ ) {
				if( isVowel(s[left])) {
						currCount--;
				}
				left++;
				if (isVowel(s[right])) {
					currCount++;
					maxCount = max(currCount,maxCount);
				}
			}
			return maxCount;
		}
};
int main() {
	Solution s;

	// string inp1{"aciiidef"};
	// int ans1 = s.maxVowels(inp1,3);
	string inp1{"qempburycnhrvvccr"};
	int ans1 = s.maxVowels(inp1,13);
	cout << ans1 << '\n';

	return 0;
}
