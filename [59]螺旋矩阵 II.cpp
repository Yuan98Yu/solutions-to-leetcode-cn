#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int cur_min = 0, cur_max = n - 1;
        int count = 0;
        while (cur_min <= cur_max) {
            // top
            for (size_t c = cur_min; c <= cur_max; ++c)
                ans[cur_min][c] = ++count;
            // right
            for (size_t r = cur_min+1; r <= cur_max; ++r)
                ans[r][cur_max] = ++count;
            if (cur_min < cur_max){
            // bottom
                for (size_t c = cur_max-1; c > cur_min; --c)
                    ans[cur_max][c] = ++count;
            // left
                for (size_t r = cur_max; r > cur_min; --r)
                    ans[r][cur_min] = ++count;
            } 
            ++cur_min;
            --cur_max;
        }

        return ans;
    }
};