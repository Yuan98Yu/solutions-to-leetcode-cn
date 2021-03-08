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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		int max_depth = -1;
		dp(root, max_depth, ans, 0);

		return ans;
	}
private:
	void dp(TreeNode* root, int& max_depth, vector<int>& ans, int cur_depth) {
		if (root == nullptr)
			return;

		if (cur_depth == max_depth + 1) {
			ans.push_back(root->val);
			++max_depth;
		}
		dp(root->right, max_depth, ans, cur_depth + 1);
		dp(root->left, max_depth, ans, cur_depth + 1);
	}	
};