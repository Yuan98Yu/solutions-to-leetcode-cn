#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int find_1 = false;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 1)
				find_1 = true;
			if (nums[i] <= 0 || nums[i] > nums.size())
				nums[i] = 1;
		}
		if (!find_1)
			return 1;

		for (int i = 0; i < nums.size(); ++i) {
			if ((nums[abs(nums[i]) - 1] > 0))
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
		}
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] > 0)
				return i + 1;

		return nums.size() + 1;
	}
};