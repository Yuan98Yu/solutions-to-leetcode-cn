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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		dp(root, ans);
	}
	void dp(TreeNode* root, vector<int>& ans) {
		if (root == nullptr)
			return;
		ans.push_back(root->val);
		dp(root->left, ans);
		dp(root->right, ans);
	}
};