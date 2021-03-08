#include <cstdlib>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int depth = 0;
		return dp(root);
	}
private:
	int dp(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left_height = count_height(root->left);
		int right_height = count_height(root->right);
		if (left_height == right_height) {
			return (1 << left_height) + dp(root->right);
		}	
		else {
			return dp(root->left) + (1 << right_height);
		}
	}
	int count_height(TreeNode* root) {
		int height = 0;
		while (root != nullptr) {
			++height;
			root = root->left;
		}
		return height;
	}
};