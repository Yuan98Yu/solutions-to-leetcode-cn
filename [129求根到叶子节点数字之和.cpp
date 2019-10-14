#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		return dp(root, 0);
	}
private:
	int dp(TreeNode* root, int tmp_sum) {
		if (root == nullptr)
			return 0;
		tmp_sum = tmp_sum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr)
			return tmp_sum;

		return dp(root->left, tmp_sum) + dp(root->right, tmp_sum);
	}
};