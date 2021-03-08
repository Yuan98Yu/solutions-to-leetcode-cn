#include <cstdlib>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int height = -1;
		return dp(root, height);
	}
	bool dp(TreeNode* root, int& height) {
		if (root == NULL) {
			height = 0;
			return true;
		}

		int left_height = -1;
		int right_height = -1;
		bool is_left_balanced = dp(root->left, left_height);
		bool is_right_balanced = dp(root->right, right_height);
		height = (left_height > right_height ? left_height : right_height) + 1;

		return is_left_balanced && is_right_balanced && left_height - right_height <= 1 && left_height - right_height >= -1;
	}
};