#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;
		sort(nums.begin(), nums.end());
		int max_len = 1;
		int tmp = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1] + 1)
				++tmp;
			else if (nums[i] != nums[i - 1]) {
				if (tmp > max_len)
					max_len = tmp;
				tmp = 1;
			}
		}
		return max(max_len, tmp);
	}
};