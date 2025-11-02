// all subarrays (contiguous)
#include<iostream>
using namespace std;

// for now, just printing an array, can return an array too
void extractSubArray(int arr[],int i,int j){
	cout << "[";
	if (i==j) {
		cout << arr[i] << "]\n";
		return;
	}
	for(int it{i};it<j;it++){
		cout << arr[it] << ",";
	} cout <<arr[j] << "]\n";
}
void getAllSubarray(int arr[],int size){

	for (int i{0}; i<size; i++ ) {
		for (int j{i}; j<size; j++) {
			// i to j is a subarray
			// cout << "found subarray: " << i << " to " << j << '\n';
			extractSubArray(arr,i,j);
		}
	}
}
int main() {
	int arr[] {2,3,-8,7,-1,2,3};
	getAllSubarray(arr, 7);
}
