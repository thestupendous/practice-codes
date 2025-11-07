#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		int compress(vector<char>& chars) {
			char prev{chars[0]},toAppend{'\0'};
			unsigned currCount{0},toPlace{0};
			// bool firstSame{false};
			for (size_t i{1};i<chars.size();i++) {
				if(chars[i] == prev) {
					currCount++;
					if(currCount==1) {
						// first repetition found
						cout << "setting toplace " << toPlace << 
							"at i : " << i << '\n';
						toPlace=i-1;
					}

				} else {
					// now fill out all the repititions with count
					if (currCount>1) {
						cout << "group processing" << i << '\n';
						chars[toPlace++] = prev;
						// now to place number to char array
						string digits{std::to_string(currCount)};
						for (char ch: digits) {
							chars[toPlace++] = ch;
						}
						currCount = 0;
					} else {
						// when the char appeared only once
						cout << "single character pushing" << i << '\n';
						chars[toPlace++] = prev;
						if(i==chars.size()-1)
							chars[toPlace++] = chars[i];
					}
				}
				prev=chars[i];
			}
			return toPlace;
		}
};

int main() {
	Solution s;
#if 0
	vector<char> v1{'a','a','a','a','m','n'};
	int ans1 = s.compress(v1);
	for (char ch: v1) {
		cout << ch << ',';
	}
	cout << '\n';
	cout << ans1 << '\n';

	vector<char> v2{'a','b','c','p','g'};
	int ans2 = s.compress(v2);
	for (char ch: v2) {
		cout << ch << ',';
	}
	cout << '\n';
	cout << ans2 << '\n';
#endif

	vector<char> v3{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	int ans3 = s.compress(v3);
	for (char ch: v3) {
		cout << ch << ',';
	}
	cout << '\n';
	cout << ans3 << '\n';

	return 0;
}
