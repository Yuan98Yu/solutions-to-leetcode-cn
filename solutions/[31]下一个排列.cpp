#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		bool flag = false;
		int i;
		for (i = nums.size() - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			reverse(nums.begin() + i, nums.end());
			int p2;
			for (p2 = i; p2 < nums.size() - 1 && nums[p2] <= nums[i - 1]; ++p2);

			swap(nums[i - 1], nums[p2]);
		}
		else {
			reverse(nums.begin(), nums.end());
		}

	}
};