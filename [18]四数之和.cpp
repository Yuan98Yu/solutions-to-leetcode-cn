#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	/*
		既然已经写了两数之和，三数之和，现在写到四数之和，不如直接写一个k数之和（k>=2）
	*/
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4)
			return vector<vector<int>>();
		sort(nums.begin(), nums.end());
		return kSum(nums, target, 4, 0);
	}

	//输入：nums:	已排序的从小到大的数组
	//		k:		当前为k数之和
	//		begin:	数组(nums)的起始位置
	vector<vector<int>> kSum(vector<int>& nums, int target, int k, int start) {
		vector<vector<int>> ans;
		if (k == 2) {
			if (nums[start] > 0 && nums[start] - target > 0) return ans;
			int left = start;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = nums[left] + nums[right] - target;
				if (sum == 0) {
					// cout << "k==2, find: " << nums[left] << " " << nums[right] << endl;
					ans.push_back(vector<int>{ nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) left++; // 去重
					while (left < right && nums[right] == nums[right - 1]) right--; // 去重
					left++;
					right--;
				}
				else if (sum < 0)
					left++;
				else
					right--;
			}
		}
		else if (k >= 2) {
			for (int i = start; i < nums.size() - k + 1; i++) {
				vector<vector<int>> tmp = kSum(nums, target - nums[i], k - 1, i + 1);
				if (!tmp.empty()) {
					for (vector<int>& l : tmp) {
						l.push_back(nums[i]);
					}
					ans.insert(ans.end(), tmp.begin(), tmp.end());
				}
				while (i < nums.size() - k + 1 && nums[i] == nums[i + 1]) {
					i++;
				}
			}
		}
		return ans;
	}
};