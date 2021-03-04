#include <cstdlib>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		return dp(root->left, root->right);
	}
	bool dp(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p == NULL || q == NULL)
			return false;
		else
			return p->val == q->val && dp(p->left, q->right) && dp(p->right, q->left);
	}
};