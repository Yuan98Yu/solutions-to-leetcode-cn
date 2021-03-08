#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = nums[0] + nums[1] + nums[2];
		if (nums.size() == 3)
			return ans;

		int diff_value = abs(ans - target);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] > 0 && nums[i] - target > diff_value) break;

			int fix = nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = fix + nums[left] + nums[right];
				if (sum == target) {
					return target;
				}
				else if (sum < target)
					left++;
				else
					right--;
				if (abs(sum - target) < diff_value) {
					ans = sum;
					diff_value = abs(sum - target);
				}
			}
		}
		return ans;
	}
};