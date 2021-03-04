class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (long m = 5; m <= n; m *= 5) {
            ans += n/m;
        }
        return ans;
    }
};