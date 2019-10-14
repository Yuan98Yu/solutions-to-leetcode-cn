#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) break; // �����ǰ���ִ���0��������֮��һ������0�����Խ���ѭ��
			if (i > 0 && nums[i] == nums[i - 1]) continue; // ȥ��
			int fix = nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = fix + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back(vector<int>{fix, nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) left++; // ȥ��
					while (left < right && nums[right] == nums[right - 1]) right--; // ȥ��
					left++;
					right--;
				}
				else if (sum < 0)
					left++;
				else
					right--;
			}
		}
		return res;
	}
};