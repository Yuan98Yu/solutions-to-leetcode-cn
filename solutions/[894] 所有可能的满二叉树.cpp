#include <cstdlib>
#include <map>
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
	vector<TreeNode*> allPossibleFBT(int N) {
		if (memo.find(N) == memo.end()) {
			vector<TreeNode*> ans;
			if (N == 1) {
				ans.push_back(new TreeNode(0));
			}
			else if (N % 2 == 1) {
				for (int x = 0; x < N; ++x) {
					int y = N - 1 - x;
					for (TreeNode* left : allPossibleFBT(x)) {
						for (TreeNode* right : allPossibleFBT(y)) {
							TreeNode* root = new TreeNode(0);
							root->left = left;
							root->right = right;
							ans.push_back(root);
						}
					}
				}
			}
			memo[N] = ans;
		}
		return memo[N];
	}

private:
	map<int, vector<TreeNode*>> memo;
};