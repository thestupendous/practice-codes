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
	// in window
	map<char,bool> alphabets;
	unsigned start{0},changeInd{0};
	for(unsigned i{0};i<inp.size();i++){
		if (alphabets[inp[i]] == true) {
			while(inp[start]!=inp[i]){
				if(

			}
				



}

int main(){
	string inp;
	cin >> inp;

	std::string_view result = longestSubstr(inp);
	cout<< result << "\n";

	return 0;
}


