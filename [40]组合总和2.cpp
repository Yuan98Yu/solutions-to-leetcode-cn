#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> path;

		sort(candidates.begin(), candidates.end());
		_dfs(candidates, 0,
			path, ans, target);

		return ans;
	}

	void _dfs(vector<int>& candidates, int start,
		vector<int>& path, vector<vector<int>>& ans, int target) {
		if (target == 0) {
			ans.push_back(path);
			return;
		}
		if (start >= candidates.size())
			return;

		for (int i = start; i < candidates.size(); ++i) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			int tmp_target = target - candidates[i];
			if (tmp_target < 0)
				continue;
			path.push_back(candidates[i]);
			_dfs(candidates, i + 1,
				path, ans, tmp_target);
			path.pop_back();
		}
	}
};