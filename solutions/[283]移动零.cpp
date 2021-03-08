#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int num : nums) {
            if (num != 0)
                nums[p++] = num;
        }
        for (; p < nums.size(); ++p)
            nums[p] = 0;
    }
};