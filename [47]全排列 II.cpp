#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> path;
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());
		_dfs(nums, nums.size(), path,
			ans, used);

		return ans;
	}

	void _dfs(vector<int>& nums, int n, vector<int>& path,
		vector<vector<int>>& ans, vector<bool>& used) {
		if (n == 0) {
			ans.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (!used[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
					continue;
				used[i] = true;
				path.push_back(nums[i]);
				_dfs(nums, n - 1, path, ans, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
};