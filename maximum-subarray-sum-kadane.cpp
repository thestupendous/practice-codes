/*
 * Problem -
 * Given an integer array arr[], find the subarray (containing at
 * least one element) which has the maximum possible sum, and 
 * return that sum. A subarray is a continuous part of an array.
 *
 * Created a result struct object that contains 3 fields -
 *   - max sum 
 *   - starting index of result subarray
 *   - ending index of result subarray
 * */

#include<iostream>
using namespace std;

struct SubArray {
	int maxSum;
	int maxLeft;
	int maxRight;
	SubArray(): maxSum{0}, maxLeft{0}, maxRight{0} {}
	~SubArray(){
		cout<<"deleted\n";
	}
};

SubArray* maxSubarraySum(int arr[],int size) {
	SubArray *result = new SubArray;
	// check if all negatives/zeroes
	unsigned countNeg{0},countZero{0};
	int maxNegative=-99999999;
	for (int i{0};i<size;i++ ) {
		if (arr[i]<0) {
			countNeg++;
			if (maxNegative<arr[i])
				maxNegative = arr[i];
		}
		else if (arr[i]==0) countZero++;
	}
	if (countNeg == size) {
		result->maxSum=maxNegative;
		return result;
	} else if (countZero == size) {
		return 0;
	}
	

	int sum{0},left{0};
	for (int i{0};i<size;i++ ) {
		if(sum<=0) { 
			// reset left
			left = i;
			sum=0;
		}
		
		sum += arr[i];
		if (result->maxSum<sum) {
			result->maxSum = sum;
			result->maxLeft = left;
			result->maxRight = i;
		}
	}
	return result;
}

int main(){
	int arr[] {2,3,-8,7,-1,2,3};
	SubArray* maxResult;
	maxResult=maxSubarraySum(arr,7);
	cout << maxResult->maxSum << '\n';
	cout << maxResult->maxLeft << ',' << maxResult->maxRight << '\n';
	maxResult->~SubArray();
	cout<<'\n';

	int arr2[] {200,-100,300,-20000,50,50,50};
	SubArray* maxResult2;
	maxResult2=maxSubarraySum(arr2,7);
	cout << maxResult2->maxSum << '\n';
	cout << maxResult2->maxLeft << ',' << maxResult2->maxRight << '\n';
	maxResult2->~SubArray();
	cout<<'\n';

	int arr3[] {200,-100,300,-20000,50,50,50,100,100};
	SubArray* maxResult3;
	maxResult3=maxSubarraySum(arr3,9);
	cout << maxResult3->maxSum << '\n';
	cout << maxResult3->maxLeft << ',' << maxResult3->maxRight << '\n';
	maxResult3->~SubArray();
	cout<<'\n';

	int arr4[] {200,-100,300,-20000,50,50,50,100,151};
	SubArray* maxResult4;
	maxResult4=maxSubarraySum(arr4,9);
	cout << maxResult4->maxSum << '\n';
	cout << maxResult4->maxLeft << ',' << maxResult4->maxRight << '\n';
	maxResult4->~SubArray();
	cout<<'\n';

	return 0;
}
