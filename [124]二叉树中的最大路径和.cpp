#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int ans = -99999;
		dp(root, ans);
		return ans;
	}
	int dp(TreeNode* root, int& ans) {
		if (root == nullptr)
			return 0;

		if (root->val > ans)
			ans = root->val;
		if (root->left == nullptr && root->right == nullptr) {
			return root->val;
		}


		int left = dp(root->left, ans);
		int right = dp(root->right, ans);
		int ret = (left > 0 || right > 0 ? (left > right ? left : right) : 0) + root->val;
		int tmp = (left > 0 && right > 0 ? left + right + root->val : ret);
		if (tmp > ans)
			ans = tmp;
		return ret;
	}
};