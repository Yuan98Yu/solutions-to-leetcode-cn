#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> cur;
		dp(n, k, 1, cur, ans);
		return ans;
	}
	void dp(int n, int k, int start, vector<int>& cur, vector<vector<int>>& ans) {
		if (k == 0)
			ans.push_back(cur);
		else {
			for (int i = start; i < n - k + 2; ++i) {
				cur.push_back(i);
				dp(n, k - 1, i + 1, cur, ans);
				cur.pop_back();
			}
		}
	}
};