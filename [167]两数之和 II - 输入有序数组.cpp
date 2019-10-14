#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ans;
		for (int left = 0; left < numbers.size(); ++left) {
			int r_idx = find_right_index(numbers, left + 1, target - numbers[left]);
			if (r_idx != -1) {
				ans.push_back(left + 1);
				ans.push_back(r_idx + 1);
				break;
			}
		}
		return ans;
	}
private:
	int find_right_index(vector<int>& numbers, int left, int target) {
		int right = numbers.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (numbers[mid] == target)
				return mid;
			else if (numbers[mid] > target)
				right = mid;
			else
				left = mid + 1;
		}
		return -1;
	}
};