#include <vector>
using namespace std;

class Solution {
public:
	/*
		1.和[39][40]基本一样的写法
	*/
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> path;
		_dfs(nums, path, ans);

		return ans;
	}
	void _dfs(vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans) {
		int len = candidates.size();
		if (len == 0) {
			ans.push_back(path);
			return;
		}

		for (int i = 0; i < len; ++i) {
			int tmp = candidates[0];
			path.push_back(candidates[0]);
			candidates.erase(candidates.begin());
			_dfs(candidates, path, ans);
			candidates.push_back(tmp);
			path.pop_back();
		}
	}

	void _swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	/*
		2.略有不同的写法
	*/
	vector<vector<int>> permute2(vector<int>& nums) {
		vector<vector<int>> ans;

		_dfs2(nums, nums.size(), ans);

		return ans;
	}

	void _dfs2(vector<int>& nums, int n, vector<vector<int>>& ans) {
		if (n == 0) {
			ans.push_back(nums);
			return;
		}

		for (int i = 0; i < n; ++i) {
			_swap(nums[i], nums[n - 1]);
			_dfs2(nums, n - 1, ans);
			_swap(nums[i], nums[n - 1]);
		}
	}
};