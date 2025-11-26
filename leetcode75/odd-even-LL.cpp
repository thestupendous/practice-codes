#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addNode(ListNode * &head,int val){
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
		cout << ptr->val << ",";
		ptr = ptr->next;
	}
	cout << ptr->val << "]\n";
}
/**
*/
class Solution {
	public:
		ListNode* oddEvenList(ListNode* &head) {
			if (head == nullptr || head->next == nullptr) return head;

			ListNode* odd = head;
			ListNode* even = head->next;
			ListNode* evenHead = even;

			while (even != nullptr && even->next != nullptr) {
				odd->next = even->next;
				odd = odd->next;
				even->next = even->next->next;
				even = even->next;
			}

			odd->next = evenHead; // Connect odd list to even list
			return head;
		}
};
int main() {
	cout << "log: start\n";
	Solution s;
	ListNode *head{nullptr};
	addNode(head,1);
	addNode(head,100);
	addNode(head,2);
	addNode(head,200);
	addNode(head,3);
	addNode(head,300);
	addNode(head,4);
	// addNode(head,400);

	cout<< "printing list: ";
	printList(head);

	ListNode *ans1;
	ans1 = s.oddEvenList(head);
	cout << "Result : " ;
	printList(ans1);

	return 0;
}
