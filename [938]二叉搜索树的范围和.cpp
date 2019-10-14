#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, const int& L, const int& R) {
		if (root == nullptr)
			return 0;

		if (root->val >= L && root->val <= R)
			return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
		else if (root->val < L)
			return rangeSumBST(root->right, L, R);
		else
			return rangeSumBST(root->left, L, R);
	}
};