#include <string>
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		if (root == nullptr)
			return ans;

		string path;
		dp(root, path, ans);

		return ans;
	}
private:
	void dp(TreeNode* root, string path, vector<string>& ans) {
		if (root == nullptr)
			return;

		path += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			ans.push_back(path);
			return;
		}

		path += "->";
		dp(root->left, path, ans);
		dp(root->right, path, ans);
	}
};