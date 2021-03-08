#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;

		if (!isValidBST(root->left))
			return false;
		if (root->val <= pre)
			return false;
		this->pre = root->val;
		return isValidBST(root->right);
	}
private:
	long pre = LONG_MIN;
};