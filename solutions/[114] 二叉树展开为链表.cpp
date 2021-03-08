#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		while (root != nullptr) {
			if(root->left != nullptr) {
				TreeNode* pre = root->left;
				while (pre->right != nullptr)
					pre = pre->right;
				pre->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
};