//  number of numbers between 1 and N that are not divisible
//  by 2, 3 and 5
#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int num;
    cin>> num;
    unsigned ans{0};
    for(unsigned check{1};check<=num;check++) {
        if (check%2!=0 && check%3!=0 && check%5!=0 ){
            ans++;
						cout << "aya\n";
				}
    }
    cout << ans << '\n';
}
