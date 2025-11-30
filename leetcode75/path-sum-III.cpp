/**
 * Definition for a binary tree node.
 */
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
    void pathSumRecursion(TreeNode* root,int upar, const int &targetSum, int &ans) {
        if(!root) return;
        if(root->val==targetSum) ans++;

        // yaha se lekar pura neeche
        if (upar == targetSum) ans++;
        pathSumRecursion(root->left, root->val, targetSum, ans);
        pathSumRecursion(root->right, root->val, targetSum, ans);


        // chalte jaao
        if (upar+root->val == targetSum) ans++;
        pathSumRecursion(root->left, upar+root->val, targetSum, ans);
        pathSumRecursion(root->right, upar+root->val, targetSum, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
			int ans;
			pathSumRecursion(root,0,targetSum,ans);
			return ans;
		}
};
