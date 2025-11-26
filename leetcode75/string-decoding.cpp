/*
 * word - a substring of the string that occurs many times 
 * reps - repititions count of a word.
*/
#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:
		string decodeString(string s) {
			short int length(s.size());
			string ans;
			int numrange{},wordrange{};
			for (short int i{0}; i < length; i++) {
				/* ------ if the word comes 'reps' times ------ */
				numrange = s[i] - '0';
				if (numrange >= 0 && numrange <= 9) {

					/* ----- get num of reps ---------*/
					string numWord{};
					while (numrange >= 0 && numrange <= 9) {
						numWord += s[i];
						numrange = s[i] - '0';
						i++;
					}

					/* --------- get word -----------*/
					string word{""};
					i++; // now i must point to the word (after passing '[' char)
					wordrange = s[i] - 'a';
					while(wordrange>=0 && wordrange<=26) {
						word+=s[i];
						i++;
					}

					/* ------- ans+= : add word, times the rep count ---------*/
					int num = std::stoi(numWord);
					while(num) {
						ans += word;
					}

				/* ------ if the word comes just once ------ */
					wordrange = s[i] - 'a';
				} else if (wordrange>=0 && wordrange<=26){
					/* --------- get word -----------*/
					string word{""};
					wordrange = s[i] - 'a';
					while(wordrange>=0 && wordrange<=26) {
						word+=s[i];
						i++;
					}
					ans += word;
				}
			}
			return ans;
		}
};
