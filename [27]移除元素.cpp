/*
	˫ָ��
*/
#include <vector>
using namespace std;

class Solution {
public:
	/*
		��1��ƽ��
	*/
	int removeElement(vector<int>& nums, int val) {
		int count = 0;
		int i = 0;
		while(i < nums.size()) {
			while (i < nums.size() && nums[i] == val)
				i++;
			if (i == nums.size())
				break;
			nums[count++] = nums[i++];
		}
		return count;
	}
	/*
		��2������
	*/
	int removeElement2(vector<int>& nums, int val) {
		int count = 0;
		int i = nums.size() - 1;
		while (count <= i) {
			if (nums[count] == val)
				nums[count] = nums[i--];
			else
				count++;
		}
		return i + 1;
	}
};