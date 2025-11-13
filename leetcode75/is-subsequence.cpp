#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int curr{0};
        for (char c: t) {
            if (c==s[curr]) {
                curr++;
            }
        }
        cout << curr << '\n';
        if (curr==s.size()) return true;
        return false;
    }
};
int main() {
	Solution s;
	cout << s.isSubsequence("ace","abcdef") << '\n';
}
