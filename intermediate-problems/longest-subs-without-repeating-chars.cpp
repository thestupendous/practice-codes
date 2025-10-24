/*
 * program to find the length of the longest substring without 
 * repeating characters in a given string. A substring is a 
 * contiguous sequence of characters within a string.
	 */

#include<cstring>

#include<iostream>
#include<string>
#include<string_view>
#include<map>
using std::map,std::string,std::cin,std::cout;

std::string_view longestSubstr(std::string_view inp){
	map<char,bool> alphabets;
	
	unsigned startInd{0}, diff{0}, maxDiff{0};
	unsigned bestStart{0}, bestEnd{0}, bestDiff{0};
	for (unsigned i{0}; i<inp.size(); i++) {
		if ( alphabets.find(inp[i]) != alphabets.end()) {
			// reset

			startInd+=1;
		} 
		alphabets[inp[i]] = true;
		if (i-startInd > bestDiff) {
			bestDiff = i-startInd;
			bestStart = startInd;
		}
	}
	cout << "maxdiff " << maxDiff << '\n';

	return inp.substr(bestStart,maxDiff+1);

}

int main(){
	string inp;
	cin >> inp;

	std::string_view result = longestSubstr(inp);
	cout<< result << "\n";

	return 0;
}


