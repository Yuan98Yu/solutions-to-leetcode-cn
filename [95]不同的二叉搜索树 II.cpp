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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>{};
		return dp(1, n);
	}
	vector<TreeNode*> dp(int front, int back){
		if (memo.find(make_pair(front,back)) == memo.end()) {
			vector<TreeNode*> ans;
			if (front == back) {
				TreeNode* root = new TreeNode(front);
				ans.push_back(root);
			}
			else if(front > back){
				ans.push_back(nullptr);
			}
			else {
				for (int i = front; i <= back; ++i) {
					vector<TreeNode*> lefts = dp(front, i - 1);
					vector<TreeNode*> rights = dp(i + 1, back);
					for (TreeNode* left : lefts) {
						for (TreeNode* right : rights) {
							TreeNode* root = new TreeNode(i);
							root->left = left;
							root->right = right;
							ans.push_back(root);
						}
					}
				}

			}
			memo[make_pair(front, back)] = ans;
		}

		return memo[make_pair(front, back)];
	}
private:
	map<pair<int,int>, vector<TreeNode*>> memo;
};