#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		map<int, int> m;
		for (int i = 0; i < inorder.size(); ++i)
			m[inorder[i]] = i;
		int pre_idx = 0;
		return dp(m, preorder, inorder, pre_idx, 0, inorder.size());
	}
	TreeNode* dp(map<int, int>& m, vector<int>& preorder, vector<int>& inorder, int& pre_idx, int in_left, int in_right) {
		if (in_left == in_right)
			return nullptr;

		TreeNode* root = new TreeNode(preorder[pre_idx]);
		int idx = m[preorder[pre_idx]];
		pre_idx++;
		root->left = dp(m, preorder, inorder, pre_idx, in_left, idx);
		root->right = dp(m, preorder, inorder, pre_idx, idx + 1, in_right);

		return root;
	}
};