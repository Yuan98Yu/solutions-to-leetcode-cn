#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return 0;
		
		return (root->left && root->left->left == nullptr && root->left->right == nullptr ?
			root->left->val : 0) + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};