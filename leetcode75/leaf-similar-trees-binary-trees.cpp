/**
	Definition for a binary tree node.
 *
 */
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
	public:
		void inorderWithFill(TreeNode* root, vector<int> &arr) {
			if (!root) return;
			if (!root->left && !root->right) {
				arr.push_back(root->val);
				return;
			}
			inorderWithFill(root->left,arr);
			inorderWithFill(root->right,arr);
		}
		bool leafSimilar(TreeNode* root1, TreeNode* root2) {
			vector<int> arr1,arr2;
			inorderWithFill(root1,arr1);
			inorderWithFill(root2,arr2);
			if (arr1.size() != arr2.size()) return false;
			size_t len1{arr1.size()};
			for (unsigned i{0};i<len1;i++) {
				if (arr1[i]!=arr2[i]) return false;
			}
			return true;
		}
};
