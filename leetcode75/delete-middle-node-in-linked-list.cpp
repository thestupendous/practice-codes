#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
			if(head==nullptr) return nullptr;
			if(head->next==nullptr) return nullptr;
			if(head->next->next==nullptr) {
				ListNode *temp = head->next;
				head->next=nullptr;
				delete temp;
				return head;
			}
			ListNode *next{head}, *doubleNext{head}, *prev{head};
			next = prev = head;
			while(doubleNext!=nullptr && doubleNext->next!=nullptr){
				prev=next;
				doubleNext = doubleNext->next->next;
				next = next->next;
			}

			ListNode *temp = prev->next;
			prev->next = prev->next->next;
			delete temp;

			return head;
    }
};
