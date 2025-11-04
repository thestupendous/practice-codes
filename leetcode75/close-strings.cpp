#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> m1,m2;
				if (word1.size() != word2.size()) return false;
        for(char c: word1) {
            m1[c]++;
        }
        for(char c: word2) {
            m2[c]++;
        }

				
				for(auto it{m1.begin()}; it!=m1.end(); it++ ) {
					if ( m2.find(it->first) == m2.end() ) 
						return false;
				}

				vector<int> freq1,freq2;
				for(auto it{m1.begin()}; it!=m1.end(); it++ ) {
					freq1.push_back(it->second);
				}
				for(auto it{m2.begin()}; it!=m2.end(); it++ ) {
					freq2.push_back(it->second);
				}
				std::sort(freq1.begin(),freq1.end());
				std::sort(freq2.begin(),freq2.end());
				if (freq1.size() != freq2.size())
					return false;
				for(unsigned i{0};i<freq1.size();i++) {
					if (freq1[i] != freq2[i])
						return false;
				}

				return true;
    }
};
int main() {
	// no need, it runs ✌️
}
