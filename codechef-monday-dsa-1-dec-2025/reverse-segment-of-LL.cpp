// TODO solve this
#include <iostream>
using namespace std;
struct Node {
	int val;
	struct Node* next;
	Node(int x){
		val = x;
		next = NULL;
	}
};
void addNode(Node * &head,int val){
	cout << "log\n";
	Node *node = new Node(val);
	if (head==nullptr) {
		head = node;
		cout<<"added 1st\n";
		return;
	}
	Node *ptr{head};
	if(ptr==nullptr) {
		cout<<"yes\n";
		return;
	}
	while(ptr->next!=nullptr) {
		ptr = ptr->next;
	}
	ptr->next=node;
}

Node* reverseSegment(Node* head, int L, int R){
	// find node
	Node* ptr{head};
	for(int i{1};i<L+1;i++) {
		ptr = ptr->next;
	}
	// cout << ptr->val << '\n';

	// reverse till R

	for(int i{L};i<=R;i++) {
		ptr
	}
}
int main() {
	Node* head;
	addNode(head,1);
	addNode(head,2);
	addNode(head,3);
	addNode(head,4);
	addNode(head,5);
	addNode(head,6);

	reverseSegment(head,3,5);

}
