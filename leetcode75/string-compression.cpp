#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		int compress(const vector<char>& chars) {
			int len(chars.size());
			string ans{""};
			unsigned prevCount{0};
			int prev{0};
			for(int i{1};i<len;i++) {
				if (chars[i] == chars[prev]) {
					prevCount++;
				} else {
					if (prevCount>0) {
						ans += chars[prev] + to_string(1+prevCount);
					} else if(prevCount==0) {
						ans += chars[prev];
					}
					prevCount =0;
				}
				prev=i;
			}
			cout << "len, chars[len-1], chars[len-2] : " <<len<< ','<<
				len-1<<","<<len-2 << '\n';
			if (len-2>=0 && chars[len-1]==chars[len-2]) {
				if (prevCount>0) {
					ans += chars[prev] + to_string(1+prevCount);
				}	
			} else {
				ans += chars[prev];
			}


			cout << "ans: " << ans << '\n';
			return ans.size();
		}
};

int main() {
	Solution s;
#if 1
	vector<char> v1{'a','a','a','a','m','n'};
	for (char ch: v1) {
		cout << ch << ',';
	}
	cout << '\n';
	int ans1 = s.compress(v1);
	cout << ans1 << '\n';

	vector<char> v2{'a','b','c','p','g'};
	for (char ch: v2) {
		cout << ch << ',';
	}
	cout << '\n';
	int ans2 = s.compress(v2);
	cout << ans2 << '\n';
#endif

	// vector<char> v3{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	vector<char> v3{'a','a'};
	for (char ch: v3) {
		cout << ch << ',';
	}
	cout << '\n';
	int ans3 = s.compress(v3);
	cout << ans3 << '\n';

	vector<char> v4{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	for (char ch: v4) {
		cout << ch << ',';
	}
	cout << '\n';
	int ans4 = s.compress(v4);
	cout << ans4 << '\n';


	return 0;
}
