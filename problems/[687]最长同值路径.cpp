#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int longestUnivaluePath(TreeNode* root) {
		int ans = 0;
		dp(root, ans);
		return ans;
	}

	int dp(TreeNode* root, int& ans) {
		if (root == nullptr) 
			return -1;

		int left = dp(root->left, ans);
		int right = dp(root->right, ans);
		int arrow_left = 0;
		int arrow_right = 0;
		if (root->left != nullptr && root->left->val == root->val)
			arrow_left = left + 1;
		if (root->right != nullptr && root->right->val == root->val)
			arrow_right = right + 1;
		ans = (arrow_left + arrow_right > ans ? arrow_left + arrow_right : ans);

		return (arrow_left > arrow_right ? arrow_left : arrow_right);
	}
};