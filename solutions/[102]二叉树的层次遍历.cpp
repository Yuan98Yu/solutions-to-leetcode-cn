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
	/*
		法1：本质上仍是深度优先遍历，但是添加了当前所在层次的参数
	*/
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		dp(ans, root, 0);
		return ans;
	}

	void dp(vector<vector<int>>& ans, TreeNode* root, int depth) {
		if (root == NULL)
			return;

		if (depth + 1 > ans.size()) {
			ans.push_back(vector<int> {root->val});
		}
		else
			ans[depth].push_back(root->val);
		dp(ans, root->left, depth + 1);
		dp(ans, root->right, depth + 1);
	}

	/*
		法2：广度优先搜索BFS
	*/
	vector<vector<int>> levelOrder2(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)
			return ans;

		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			int level_length = q.size();
			vector<int> cur_level;
			for (int i = 0; i < level_length; ++i) {
				TreeNode* now = q.front();
				q.pop();
				cur_level.push_back(now->val);
				if (now->left != NULL)
					q.push(now->left);
				if (now->right != NULL)
					q.push(now->right);
			}
			ans.push_back(cur_level);
		}

		return ans;
	}
};