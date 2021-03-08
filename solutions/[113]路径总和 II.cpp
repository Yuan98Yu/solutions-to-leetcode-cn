#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return vector<vector<int>> ();

		vector<vector<int>> ans;
		vector<int> path;
		_dfs(root, sum, ans, path);

		return ans;
	}

	void _dfs(TreeNode* root, int sum,
		vector<vector<int>>& ans, vector<int>& path) {
		if (root->left == NULL && root->right == NULL) {
			if (root->val == sum) {
				path.push_back(sum);
				ans.push_back(path);
				path.pop_back();
			}
			return;
		}
			
		int tmp_sum = sum - root->val;
		path.push_back(root->val);
		if(root->left != NULL)
			_dfs(root->left, tmp_sum, ans, path);
		if(root->right != NULL)
			_dfs(root->right, tmp_sum, ans, path);
		path.pop_back();
	}
};