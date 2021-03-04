#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> n2i;
        for (int i = 0; i < nums.size(); ++i) {
            if (n2i.find(nums[i]) != n2i.end() && n2i[nums[i]] + k >= i )
                return true;
            n2i[nums[i]] = i;
        }    
        return false;  
    }
};