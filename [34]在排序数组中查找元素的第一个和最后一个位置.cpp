#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())
			return vector<int> {-1, -1};

		vector<int> ans(2);
		int left = 0;
		int right = nums.size();

		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if (left == nums.size() || nums[left] != target) {
			ans[0] = -1;
			ans[1] = -1;
			return ans;
		}
		else {
			ans[0] = right;

			left = right;
			right = nums.size();
			while (left < right) {
				int mid = (left + right) / 2;
				if (nums[mid] <= target)
					left = mid + 1;
				else
					right = mid;
			}
		}
		ans[1] = left - 1;

		return ans;
	}
};