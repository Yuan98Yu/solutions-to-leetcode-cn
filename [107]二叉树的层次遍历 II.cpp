#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int depth = maxDepth(root);
		vector<vector<int>> ans(depth);
		dp(ans, root, 0, depth - 1);

		return ans;
	}

	void dp(vector<vector<int>>& ans, TreeNode* root, int depth, const int& max_depth) {
		if (root == NULL)
			return;


		ans[max_depth - depth].push_back(root->val);
		dp(ans, root->left, depth + 1, max_depth);
		dp(ans, root->right, depth + 1, max_depth);
	}

	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		int left_max = maxDepth(root->left);
		int right_max = maxDepth(root->right);
		return (left_max > right_max ? left_max : right_max) + 1;
	}
};