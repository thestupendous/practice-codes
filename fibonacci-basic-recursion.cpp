#include <iostream>
#include <unordered_map>
using namespace std;

long long fibRecBasic(int num) {
	if(num==1 || num==2) return 1;
	return static_cast<long long>(fibRecBasic(num-1) + fibRecBasic(num-2));
}

/*
	 long long fibRecDynamic(int num, unordered_map<int,long long> &record) {
	 if(num==1 || num==2) return 1;
	 if (record.find(num) != record.end() )
	 return record[num];
	 record[num] = static_cast<long long>(fibRecBasic(num-1) + fibRecBasic(num-2));
	 return record[num];
	 }
*/

int main() {
	int num{45};
	cout << fibRecBasic(num) << '\n';

	// unordered_map<int,long long> record;
	// cout << fibRecDynamic(num, record) << '\n';

	return 0;
}
