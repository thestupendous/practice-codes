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
		vector<vector<int>> levelOrder(TreeNode* root) {
			queue<TreeNode*> queue;
			vector<vector<int>> res;
			queue.push(root);
			unsigned qs{0};
			TreeNode *node{nullptr};
			while (!queue.empty()) {
				vector<int> level;
				qs = queue.size();
				// now pop, process and push qs times🤔
				for(int i{0};i<qs;i++) {
					node = queue.front();
					int toPush = node->val;
					cout << "processing : " << toPush << '\n';
					level.push_back(toPush);
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
				}
				res.push_back(level);
				cout<<",\n";
			}
			return res;
		}
};
int main() {
	Solution s;
	vector<vector<int>> v;
	TreeNode *head{nullptr};
	cout <<"st\n";
	add(head,10);
	cout <<"st\n";
	add(head,2);
	cout <<"st\n";
	add(head,100);
	add(head,50);
	add(head,200);
	cout<<"bahar aya\n";

	v = s.levelOrder(head);
	cout << "Will print\n";
	for (vector<int> level: v) {
		cout << '[';
		for (int val: level) {
			cout << val << ',';
		}
		cout<< "]\n";
	}
	cout <<'\n';

	return 0;
}
