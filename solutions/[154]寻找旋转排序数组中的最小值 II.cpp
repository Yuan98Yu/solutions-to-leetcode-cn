#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == nums[left]) {
				if (left == mid)
					return nums[left];
				++left;
			}
			else if (nums[mid] > nums[left]) {
				right = mid;
			}
			else {
				if (nums[mid] < nums[right])
					return left;
				left = mid + 1;
			}
		}
		return right;
	}
};