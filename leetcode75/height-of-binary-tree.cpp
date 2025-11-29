/*
 * leetcode75 - leetcode 104 - height of binary tree
*/

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
void addToBST(TreeNode * &head,int val_){
	TreeNode *prev{head},*ptr{head},
					 *node(new TreeNode(val_));
	if (head==nullptr) {
		head = node;
		cout <<"added " << val_ << '\n';
		return;
	}
	while(ptr!=nullptr){
		prev=ptr;
		if( ptr->val > val_) {
			// go right
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
	}
	if (prev->val > val_)
		prev->left = node;
	else
		prev->right = node;
	cout <<"added " << val_ << '\n';
}
class Solution {
	public:
		// height of every node
		int treeHeightAll(TreeNode* root) {
			int height( treeHeightAllApna(root,0) );
			cout<<'\n';
			return height;
		}
		// height of every node
		int treeHeightAllApna(TreeNode *root,int lastHeight) {
			if(root==nullptr) return 0;
			cout<<root->val<<": "<<lastHeight+1<<',';
			if (root->left==nullptr && root->right==nullptr) {
				return lastHeight+1;
			}
			return max(
					treeHeightAllApna(root->left,lastHeight+1),
					treeHeightAllApna(root->right,lastHeight+1)
					);
		}
		/*
		void treeHeightAllApna(TreeNode *root,int lastHeight) {
			if(root==nullptr) return ;
			cout<<root->val<<": "<<lastHeight+1<<',';
			treeHeightAllApna(root->left,lastHeight+1);
			treeHeightAllApna(root->right,lastHeight+1);
		}
		*/

		// height of whole tree - recursion
		int maxDepth(TreeNode* root) {
			if (root==nullptr) return 0;
			if (root->left==nullptr && root->right==nullptr) return 1;
			return 1+ max(maxDepth(root->left),maxDepth(root->right));
		}

		// diameter
		int maxDiameter(TreeNode* root,int &result) {
			if (root==nullptr) return 0;
			if (root->left==nullptr && root->right==nullptr) return 1;
			int leftHeight ( maxDiameter(root->left,result) );
			int rightHeight ( maxDiameter(root->right,result) );
			cout << "["<<root->val<<"]: "<<leftHeight<<','<<
				rightHeight<<'\n';
			result = max(result, leftHeight + rightHeight);
			return 1+max(leftHeight,rightHeight);
		}
};

int main() {
	Solution s;
	TreeNode *head{nullptr};
	addToBST(head,10);
	addToBST(head,2);
	addToBST(head,100);
	addToBST(head,50);
	addToBST(head,200);
	cout<<"bahar aya\n";
	int height(s.treeHeightAll(head));
	cout << "full tree height: " << height<< '\n';


	int diameterResult{0};
	s.maxDiameter(head,diameterResult);
	cout << "Diameter: " << diameterResult << '\n';
}
