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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		map<int, int> m;
		for (int i = 0; i < inorder.size(); ++i)
			m[inorder[i]] = i;
		int post_idx = postorder.size()-1;
		return dp(m, postorder, inorder, post_idx, 0, inorder.size());
	}
	TreeNode* dp(map<int, int>& m, vector<int>& postorder, vector<int>& inorder, int& post_idx, int in_left, int in_right) {
		if (in_left == in_right)
			return nullptr;

		TreeNode* root = new TreeNode(postorder[post_idx]);
		int idx = m[postorder[post_idx]];
		post_idx--;
		root->right = dp(m, postorder, inorder, post_idx, idx + 1, in_right);
		root->left = dp(m, postorder, inorder, post_idx, in_left, idx);

		return root;
	}
};