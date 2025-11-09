/*
 * this solution covers the intuitive but expensive approach
 * there is better approach which doesn't use any extra space or shortcuts
 * TODO implement that approach -
 *    - reverse whole string 
 *    - then reverse individual words in the new string 
 *    - done!! Itni simple algo thi, dekhne ke baad samajh aayi ;-)
*/#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool whitespace(char c) {
	if (c==' ' && c=='\n' && c=='\t' && c=='\v' && c=='\f')
		return true;
	else return false;
}

class Solution {
	public:
		string reverseWords(string s) {
			//cout << "Raam Raam firse! \n";
			stringstream ss(s);
			vector<string> words;

			string word;
			while (ss >> word) {
				words.push_back(word);
			}
			//cout << "Raam Raam firse1 \n";
			string res="";
			for(unsigned i=words.size()-1; static_cast<int>(i)>0; i--) {
				//cout << "["<<i<<"],";
				res += words[i] + ' ';
			}
			res+=words[0];
			//cout << '\n';
			//cout << "Raam Raam firse2 \n";

			return res;

		}
};

int main() {
	cout << "raam Raam \n";
	Solution s;

	// string s1 = "a good   example";
	string s1 = "the sky is blue";
	string ans1 = s.reverseWords(s1);
	cout << ans1 << '\n';
	return 0;
}
