// link https://www.codechef.com/skill-test/DSAMONDAY14/problems/DELDOUBLY
// TODO solve this
#include <string>
#include <iostream>
using namespace std;
#if 0
class Solution {
	public:
		char decode(string st) {
			switch (st) {
				case "00":
					return 'A';
				case "01":
					return 'T';
				case "02":
					return 'C';
				case "03":
					return 'G';
			}
		}
		string decodeDNA(int n, const string &s) {
			// write your code here 

			string letter{""}, result{""};
			short code {0};
			for(short i{0};i<n;i+=2) {
				letter = s[i]+s[i+1];
				result += decode(letter);
			}
		}
};
#endif
class Solution {
	public: char decode(string st) {
							cout << "st : " << st << "\n";
						if (st == "00")
							return 'A';
						if (st == "01")
							return 'T';
						if (st == "02")
							return 'C';
						if (st == "03")
							return 'G';

						return '0';

					}
					string decodeDNA(int n,
							const string & s) {
						// write your code here 
						cout <<"log\n";

						string letter{""}, result{""};
						short code{0};
						for (short i{0}; i < n; i += 2) {
							letter = s[i];
							letter += s[i + 1];
							result += decode(letter);
						}
						return result;
					}
};
int main() {
	int t,n;
	Solution so;
	cin>>t;
	while(t--) {
	string s;
		cin>>n;
		cin>>s;
		cout << so.decodeDNA(n,s) << '\n';
	}
}
