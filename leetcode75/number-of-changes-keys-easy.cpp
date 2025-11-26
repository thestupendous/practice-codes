#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int countKeyChanges(string s) {
        int len(s.size());
        if(len<=1) return 0;
        int changes{0};
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i{1};i<len;i++) {
            if (s[i]!=s[i-1]){
                ++changes;
            }
        }
        return changes;
    }
};
int main() {
	Solution s;
	string str1{"AaAaAaaA"};
	cout << str1 << '\n';
	cout << "changes: " << s.countKeyChanges(str1) << '\n';

	string str2{"aAbBcCababa"};
	cout << str2 << '\n';
	cout << "changes: " << s.countKeyChanges(str2) << '\n';


	return 0;
}
