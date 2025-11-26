/* this approach uses secondary vector storage
 *  as additional space for storing
 *  second half of the linked list values
*/
#include <vector>
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addNode(ListNode * &head,int val){
	cout << "log\n";
	ListNode *node = new ListNode(val);
	if (head==nullptr) {
		head = node;
		cout<<"added 1st\n";
		return;
	}
	ListNode *ptr{head};
	if(ptr==nullptr) {
		cout<<"yes\n";
		return;
	}
	while(ptr->next!=nullptr) {
		ptr = ptr->next;
	}
	ptr->next=node;
}
void printList(ListNode * &head){
	ListNode *ptr{head};
	cout << "[";
	while(ptr->next) {
		cout << ptr->val << ',';
		ptr = ptr->next;
	}
	cout << ptr->val << "]\n";
}
/**
*/
class Solution {
	public:
		int pairSum(ListNode* head) {
			vector<int> rightVals;

			/* ----- finding the middle element ----- */
			// after following loop, the first element in second half of the list is 
			// stored in `next` variable
			ListNode *next{head}, *doubleNext{head}, *prev{head};
			next = prev = head;
			while(doubleNext!=nullptr && doubleNext->next!=nullptr){
				prev=next;
				doubleNext = doubleNext->next->next;
				next = next->next;
			}

			/* ------ populate the second half vector (right vector> --- */ 
			while(next) {
				rightVals.push_back(static_cast<int>(next->val));
				next = next->next;
			}

			/* ---- find out the max sum ----- */
			int i,sum{0},maxSum{0};
			ListNode *ptr;
			cout<<"working\n";
			for(i=static_cast<int>(rightVals.size()-1), ptr=head; 
					ptr!=nullptr && i>=0; i--,ptr=ptr->next) {
				sum = ptr->val + rightVals[i];
				cout<<"Working\n";
				maxSum = max( maxSum, sum);
			}

			return maxSum;
		}
};
int main(){
	Solution s;
	ListNode *head{nullptr};
	addNode(head,1);
	cout<<"in main after 1st\n";
	addNode(head,2);
	cout<<"in main after 2st\n";
	addNode(head,1);
	addNode(head,10);
	addNode(head,7);
	addNode(head,6);

	printList(head);

	int ans1{0};
	ans1 = s.pairSum(head);
	cout << "Result : " << ans1 << '\n';

	return 0;
}
