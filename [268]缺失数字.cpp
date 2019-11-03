#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int num : nums) total += num;
        return (1 + n) * n / 2 - total;
    }
};
