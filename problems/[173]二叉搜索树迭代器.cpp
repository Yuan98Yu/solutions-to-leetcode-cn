#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		cur = root;
	}

	/** @return the next smallest number */
	int next() {
		while (cur != nullptr) {
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		int ans = cur->val;
		s.pop();
		cur = cur->right;
		return ans;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return (cur != nullptr || !s.empty());
	}
private:
	TreeNode* cur;
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */