/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void add(TreeNode * &head,int val_){
	TreeNode *prev{head},*ptr{head},
					 *node(new TreeNode(val_));
	if (head==nullptr) {
		cout <<"0\n";
		head = node;
		return;
	}
	cout <<"1\n";
	while(ptr!=nullptr){
		prev=ptr;
		if( ptr->val > val_) {
			// go right
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
		cout << "-,";
	}
	cout << "\n";
	if (prev->val > val_)
		prev->left = node;
	else
		prev->right = node;
	cout <<"added " << val_ << '\n';
}
class Solution {
	public:
		vector<int> levelOrder(TreeNode* root) {
			queue<TreeNode*> queue;
			vector<int> res;
			queue.push(root);
			unsigned qs{0};
			TreeNode *node{nullptr};
			while (!queue.empty()) {
				qs = queue.size();
				node = queue.front();
				int toPush = node->val;
				cout << "processing : " << toPush << '\n';
				res.push_back(toPush);
				if ( node->left != nullptr )
				{
					cout << "<";
					queue.push(node->left);
				}
				if ( node->right != nullptr )
				{
					cout << ">";
					queue.push(node->right);
				}
				queue.pop();
				cout<<",\n";
			}
			return res;
		}
};
int main() {
	Solution s;
	vector<int> v;
	TreeNode *head{nullptr};
	add(head,10);
	add(head,2);
	add(head,100);
	add(head,50);
	add(head,200);
	cout<<"bahar aya\n";

	v = s.levelOrder(head);
	cout << "Will print\n";
	for (int val: v) {
		cout << val << ',';
	}
	cout <<'\n';

	return 0;
}
