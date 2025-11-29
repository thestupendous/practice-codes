#include <iostream>
using namespace std;

int main() {
	// your code goes here
	unsigned len;
	cin>> len;
	int even{0},odd{0},val{0};
	for(unsigned i{0};i<len;i++) {
		cin>>val;
		if(i%2==0) even+=val;
		else odd+=val;
	}
	cout << even - odd << '\n';
}

