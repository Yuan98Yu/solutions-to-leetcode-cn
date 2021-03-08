#include <stack>
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
	void recoverTree(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* p = root;
		TreeNode* first_node = nullptr;
		TreeNode* second_node = nullptr;
		TreeNode* pre = new TreeNode(INT_MIN);
		while (p != nullptr || !s.empty()) {
			while (p != nullptr) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if (first_node == nullptr && p->val < pre->val)
				first_node = pre;
			if (first_node != nullptr && p->val < pre->val)
				second_node = p;
			pre = p;
			p = p->right;
		}
		swap(first_node->val, second_node->val);
	}
};