/*
	Ë«Ö¸Õë
*/
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int count = 0;
		for (int i = 0; i < nums.size();) {
			nums[count++] = nums[i++];
			while (i < nums.size() && nums[i] == nums[i - 1])
				i++;
		}
		return count;
	}
};