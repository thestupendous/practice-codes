/**
 * It's not yet finished
 * TODO finish it
 */
#include <limits>
#include <iostream>
using namespace std;
//---- Definition for a binary tree node ------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int goodNodeRecursion(TreeNode *root, int prevMax, int count) {
	if (root==nullptr) return 0;
	if (root->left==nullptr && root->right==nullptr) {
		if ( prevMax<=root->val ) {
			return ++count;
		} else return count;
	}
	if ( prevMax<=root->val ) {
		count++;
	}
	return goodNodeRecursion(root->left, max(prevMax,root->val),count)
		+ goodNodeRecursion(root->left, max(prevMax,root->val),count)
		- count;
}

class Solution {
	public:

		// recursive sol
		int goodNodes(TreeNode* root) {
			if (root==nullptr) return 0;
			return goodNodeRecursion(root,std::numeric_limits<int>::min(),1);
		}
};
int main() {
}
