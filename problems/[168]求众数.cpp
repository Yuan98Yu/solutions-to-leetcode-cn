#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            }
            else if (num == candidate)
                ++count;
            else
                --count;
        }
        return candidate;        
    }
};
