#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		dp(root, ans);
		return ans;
	}
	void dp(TreeNode* root, vector<int>& ans) {
		if (root == nullptr)
			return;

		dp(root->left, ans);
		ans.push_back(root->val);
		dp(root->right, ans);
	}
};