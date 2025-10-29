#include<iostream>
#include<string>
using std::string,std::cout;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
			string result{};
			for(int i{0},j{0} ; i<word1.size() || j<word2.size() ; i++,j++ ) {

				if(i<word1.size()) {
					result += word1[i];
				}
				if(j<word2.size()) {
					result += word2[j];
				}
				
			}

			return result;
        
    }
};

int main() {
	string a{"abksdfskdfskf"},
				 b{"12345"};
	Solution sol{};
	cout << sol.mergeAlternately(a,b) << '\n';

	return 0;
}

