#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		vector<int> used(nums.size(), false);
		int sum = 0;
		for (auto num : nums)
			sum += num;
		if (sum % k != 0) return false;

		return dp(nums, k, nums.size() - 1, sum / k, 0, used);
	}
	bool dp(vector<int>& nums, int k, int start, int target, int cur, vector<int>& used) {
		if (k == 0)
			return true;
		if (target == cur)
			return dp(nums, k - 1, nums.size() - 1, target, 0, used);

		for (int i = start; i >= 0; --i) {
			if (!used[i] && cur + nums[i] <= target) {
				used[i] = true;
				if (dp(nums, k, i - 1, target, cur + nums[i], used))
					return true;
				used[i] = false;
			}
		}

		return false;
	}
};