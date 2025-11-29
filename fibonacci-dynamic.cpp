#include <iostream>
#include <unordered_map>
using namespace std;
/*
 *  ---------- Comparisons are Below -------------------------------
 *
 * Running the dynamic programmed code
 * ❯ g++ fibonacci-dynamic.cpp -o dynamic.out  && time ./dynamic.out

1134903170
./dynamic.out  0.00s user 0.00s system 86% cpu 0.002 total

 *
 * Running the basic code
 * ❯ g++ fibonacci-basic-recursion.cpp -o basic.out && time ./basic.out
1134903170
./basic.out  3.52s user 0.00s system 99% cpu 3.528 total

 * */

long long fibRecBasic(int num) {
	if(num==1 || num==2) return 1;
	return static_cast<long long>(fibRecBasic(num-1) + fibRecBasic(num-2));
}

long long fibRecDynamic(int num, unordered_map<int,long long> &record) {
	if(num==1 || num==2) return 1;
	if (record.find(num) != record.end() ) {
		// cout << 'p';
		return record[num];
	}
	record[num] = static_cast<long long>(fibRecDynamic(num-1,record) 
			+ fibRecDynamic(num-2,record));
	return record[num];
}

int main() {
	int num{45};
#if 0
	cout << fibRecBasic(num) << '\n';
#endif

#if 1
	unordered_map<int,long long> record;
	cout << '\n' << fibRecDynamic(num, record) << '\n';
#endif

	return 0;
}
