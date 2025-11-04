/*
 * maje ki baat - 
 *    "Bina stack ke hi kar diya bhai ne 😆😂!!"
*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
			  // int len = static_cast<int>(s.size());
				// cout << "len " << len << '\n';
			// cout << "[[[tested\n";
        unsigned toProcess{0},starCount{0};
        for(int i{static_cast<int>(s.size()-1)}; i>=0; i--) {
						// cout << "[[[tested\n";
            if(s[i]=='*') {
                // start searching for next target
                toProcess++;
								starCount++;

            } else if (toProcess>0) {
                s[i]='*';
                toProcess--;
            }
        }
				if(s.size()-starCount <= s.size()/2 )
					return "";
				// cout << "[[[tested]]]]]]-----\n";
				char *outputChars = new char[s.size()-starCount];
				unsigned curri{0};
        for(int i{0};i<static_cast<int>(s.size());i++) {
            if (s[i]!='*') {
							*(outputChars + curri )= s[i];
							curri++;
						}
        }
				cout << "now char array: " << outputChars << '\n';
				string outputString {outputChars};
				delete [] outputChars;
        return outputString;
    }
};
int main() {
	Solution s;
	cout << s.removeStars("leet**cod*e");
	return 0;
}
