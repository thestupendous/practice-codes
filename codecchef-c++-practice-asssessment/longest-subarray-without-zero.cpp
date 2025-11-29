/*
 *
*/
#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayWithoutZero(const vector<int> &arr)  {
    int len{0},maxLen{0};
    for(int val: arr) {
        if (val!=0) {
            len++;
        } else {
            len=0;
        }
        maxLen = max(maxLen,len);
    }
		return maxLen;
}

int main() {
	// your code goes here
    unsigned n;
    cin>>n;
    vector<int> arr(n);
    for(unsigned i{0};i<n;i++) cin >> arr[i];
    cout << longestSubarrayWithoutZero(arr);
}

