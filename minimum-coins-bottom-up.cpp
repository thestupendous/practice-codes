#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
using namespace std;

int  minimumCoinsBasic(int amount,const vector<short> &coins) {
	if (amount<=0) return 0;
	int ans = numeric_limits<int>::max();
	for(short coin: coins) {
		if (amount-coin<0) continue;
		ans =  min (ans,1+minimumCoinsBasic(amount-coin, coins));
	}
	return ans;
}

int  minimumCoinsMemoized(int amount,const vector<short> &coins, unordered_map<int,int> &memo) {
	if (amount<=0) return 0;
	if (memo.find(amount) != memo.end() ) {
		return memo[amount];
	}
	memo[amount] = numeric_limits<int>::max();
	for(short coin: coins) {
		if (amount-coin<0) continue;
		memo[amount] =  min (memo[amount],1+minimumCoinsMemoized(amount-coin, coins, memo));
	}
	return memo[amount];
}

// -------------- Best Solution -----------------
int  minimumCoinsBottomUp(int amount,const vector<short> &coins,unordered_map<int,int> &memo) {
	// dekha hua algorithm
	memo[0] = 0;
	for(int i{1};i<=amount;i++) {
		for(auto coin: coins) {
			int subproblem = i-coin;
			if (subproblem < 0) continue;
			int subSolution{-1};
			if(memo.find(i) == memo.end()) {
				subSolution = memo[subproblem]+1;
				memo[i] = subSolution;
			} else if(memo.find(subproblem) == memo.end()) {
				subSolution = memo[i];
				memo[i] = subSolution;
			}
			else 
				memo[i] = min (memo[i], memo[subproblem]+1);
		}
	}
	return memo[amount];
}


int main() {
	vector<short> coins;
	coins.push_back(1);
	coins.push_back(4);
	coins.push_back(5);

	//int amount = 13;
	// int amount = 150;  // basic me 20 sec se jada
	int amount = 50;  // basic me 6 sec // memoized takes 0.0 sec !
#if 0
	cout << minimumCoinsBasic(amount,coins);
#endif

#if 0
	unordered_map<int,int> memo;
	cout << minimumCoinsMemoized(amount,coins,memo);
#endif

#if 1
	unordered_map<int,int> memo;
	cout << minimumCoinsBottomUp(amount,coins,memo);
#endif

	return 0;
}
