#include <cstdlib>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;

		int left_min = minDepth(root->left);
		int right_min = minDepth(root->right);
		if (left_min == 0 || right_min == 0)
			return left_min + right_min + 1;
		return (left_min < right_min ? left_min : right_min) + 1;
	}
};