/*
	回溯法+剪枝
	或 动态规划
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> path;
		if (candidates.empty())
			return ans;

		_dfs(candidates, 0,
			path, ans, target);

		return ans;
	}

	void _dfs(vector<int>& candidates, int p_start,
		vector<int>& path, vector<vector<int>>& ans, int target) {
		if (target == 0) {
			ans.push_back(path);
			return;
		}

		for (int i = p_start; i < candidates.size(); ++i) {
			int tmp_target = target - candidates[i];
			if (tmp_target < 0)
				continue;
			path.push_back(candidates[i]);
			_dfs(candidates, i,
				path, ans, tmp_target);
			path.pop_back();
		}
	}
};