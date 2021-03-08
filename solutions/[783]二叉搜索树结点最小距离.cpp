#include <cstdlib>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDiffInBST(TreeNode* root) {
		if (root == nullptr)
			return MAX;

		int left_min = minDiffInBST(root->left);
		int tmp = root->val - this->pre;
		this->pre = root->val;
		int right_min = minDiffInBST(root->right);
		return min(min(left_min, tmp), right_min);
	}
private:
	int pre = -99999;
	const int MAX = 0x7FFF;
};