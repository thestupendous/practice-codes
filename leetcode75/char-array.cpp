#include<iostream>
using namespace std;

int main() {
	char *arr = new char[7];
	arr[0] = 's';
	arr[1] = 's';
	arr[5] = '9';

	cout << arr << '\n';

	return 0;
}
	
