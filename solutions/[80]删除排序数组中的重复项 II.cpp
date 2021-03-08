#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int count = 1;
		int tmp = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (tmp == 2 && nums[i] == nums[count - 1]) {
				continue;
			}
			if (nums[i] != nums[count - 1])
				tmp = 0;
			nums[count++] = nums[i];
			++tmp;
		}
		return count;
	}
};