#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red_right = -1;
		int blue_left = nums.size();
		int cur;
		for (cur = 0; cur < blue_left; ) {
			if (nums[cur] == 0)
				swap(nums[cur++], nums[++red_right]);
			else if (nums[cur] == 2)
				swap(nums[cur], nums[--blue_left]);
			else
				++cur;
		}
	}
};