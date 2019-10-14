#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, threes = 0;
		for (int num : nums) {
			twos |= ones & num;
			ones ^= num;
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
	//int singleNumber2(vector<int>& nums) {
	//	int* bit = new int[nums.size()];
	//	for (int i = 0; i < nums.size(); ++i)
	//		bit[i] = 0;
	//	for (int i = 0; i < nums.size; ++i) {
	//		bit[i] += nums[i]
	//	}
	//}
};