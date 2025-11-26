/*
 * TODO - not working, complete it
*/
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
		cout << ptr->val << ",\n";
		ptr = ptr->next;
	}
	cout << ptr->val << "]\n";
}
/**
*/
class Solution {
	public:
		ListNode* oddEvenList(ListNode* &head) {
			cout<< "Log: start2\n";
			if(head==nullptr) {
				cout<< "Log: impossible1!!!!!\n";
				return head;
			}
			if (head->next==nullptr) {
				cout<< "Log: impossible2!!!!\n";
				return head;
			}
			if (head->next->next == nullptr) {
				return head;
			}
			ListNode *evenHead{head->next},*oddHead{head},*odd{head}, *even{head->next};

			int count{0};
			while ( (odd->next || even->next) && count<2) {
				if(odd->next ) {
					odd->next = odd->next->next;
					if(odd->next!=nullptr) odd=odd->next;
				  else {
						cout<<"aayi\n";
						count++;
					}
				}
				if(odd->next ) {
					even->next = even->next->next;
					if (even->next!=nullptr) 
						even=even->next;
					else
					{
						cout<<"aayi\n";
						count++;
					}
				}
			}
			cout << "bahar: " << even << ','
				<< odd << '\n';

			// add nullptr to last node of even list 
			// to mark its end 
			if(even->next) even->next = nullptr;

			// now add the even list to the end of odd list
			if(odd->next) odd->next= evenHead;
			else odd->next= evenHead;

			return oddHead;
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
