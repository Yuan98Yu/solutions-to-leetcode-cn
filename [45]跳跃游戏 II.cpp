#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int steps = 0;
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] += i;
		}
		for (int i = 0; i < nums.size() - 1;) {
			if (nums[i] >= nums.size() - 1) {
				++steps;
				break;
			}
			int max_dis = nums[i + 1];
			int max_idx = i + 1;
			for (int j = i + 2; j < nums.size() - 1 && j <= nums[i]; ++j)
				if (nums[j] > max_dis) {
					max_dis = nums[j];
					max_idx = j;
				}
			i = max_idx;
			++steps;
		}

		return steps;
	}
};