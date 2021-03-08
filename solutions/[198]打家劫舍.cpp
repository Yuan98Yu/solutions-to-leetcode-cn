#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int max1 = 0;
		int max2 = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			int cur = max(max2, max1 + nums[i]);
			max1 = max2;
			max2 = cur;
		}
		return max2;
	}
};