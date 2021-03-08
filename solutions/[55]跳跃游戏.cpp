#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1)
			return true;
		int start = 0;
		int end = nums[0];
		for (int i = 0; i < end;) {
			for (int j = i + 1; j < nums.size() - 1 && j <= end; ++j) {
				if (nums[j] + j > end) {
					end = nums[j] + j;
				}
			}
			if (end >= nums.size() - 1)
				return true;
			i = nums[i] + i + 1;
		}

		return false;
	}
};