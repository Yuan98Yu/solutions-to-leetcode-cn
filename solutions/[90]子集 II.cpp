/*
	与[47]的去重思路相同
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> path;
		vector<bool> used(nums.size(), false);
		_dfs(nums, 0, path, ans, used);

		return ans;
	}

	void _dfs(vector<int>& nums, int start,
		vector<int>& path, vector<vector<int>>& ans, vector<bool> used) {
		ans.push_back(path);
		for (int i = start; i < nums.size(); ++i) {
			if (!used[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
					continue;
				path.push_back(nums[i]);
				used[i] = true;
				_dfs(nums, i + 1, path, ans, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
};