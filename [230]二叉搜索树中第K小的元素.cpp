#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int ans = 0;
		dp(root, k, ans);
		return ans;
	}
	void dp(TreeNode* root, int& k, int& ans) {
		if (root == nullptr)
			return;
		dp(root->left, k, ans);
		--k;
		if (k == 0) {
			ans = root->val;
			return;
		}
		dp(root->right, k, ans);			
	}
};