#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max=nums[0];
		int cum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (cum < 0)
				cum = 0;
			cum += nums[i];
			if (cum > max)
				max = cum;
		}
		return max;
	}
};