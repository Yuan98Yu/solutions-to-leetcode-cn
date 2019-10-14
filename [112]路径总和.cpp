#include <cstdlib>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
	 bool hasPathSum(TreeNode* root, int sum) {
		 if (root == NULL)
			 return false;
		 if (root->left == NULL && root->right == NULL)
			 return sum == root->val;

		 int tmp_sum = sum - root->val;
		 return hasPathSum(root->left, tmp_sum) || hasPathSum(root->right, tmp_sum);
	 }
 };