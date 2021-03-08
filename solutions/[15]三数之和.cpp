#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) break; // 如果当前数字大于0，则三数之和一定大于0，所以结束循环
			if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
			int fix = nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = fix + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back(vector<int>{fix, nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) left++; // 去重
					while (left < right && nums[right] == nums[right - 1]) right--; // 去重
					left++;
					right--;
				}
				else if (sum < 0)
					left++;
				else
					right--;
			}
		}
		return res;
	}
};