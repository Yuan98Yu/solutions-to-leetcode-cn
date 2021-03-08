#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        size_t t = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int op1 = nums[0]*nums[1]*nums[t];
        int op2 = nums[t-2]*nums[t-1]*nums[t];
        return max(op1, op2);
    }
};