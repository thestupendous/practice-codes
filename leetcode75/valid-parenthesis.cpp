#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool matching(char opening,char closing){
	if (opening == '[' && closing == ']')
		return true;
	if (opening == '{' && closing == '}')
		return true;
	if (opening == '(' && closing == ')')
		return true;
	return false;
}



class Solution {
	public:
		bool isValid(string s) {
			if (s.size()==0) return false;
			stack<char> st;
			for (char ch: s) {
				if (ch == '(' || ch == '[' || ch == '{' ) {
					// found opening, push to stack
					st.push(ch);
				} else if (ch == ')' || ch == ']' || ch == '}' ) {
					if ( st.empty() ) return false;
					if ( ! matching(st.top(),ch) ) {
						return false;
					} else {
						st.pop();
					}
				}
			}
			if ( !st.empty() ) return false;
			else return true;
		}
};


int main() {
	Solution s;
	string str1;
	cin>>str1;

	string ans1 = ( s.isValid(str1) ) ? ( "Valid\n" ) : ("Not valid\n");
	cout << ans1;

	return 0;
}

