#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return bt (1, k, n);
    }

    vector<vector<int>> bt(int start, int k, int n) {
        vector<vector<int>> ans;
        if (k == 1) {
            if (start<=n && n <= 9) {
                ans.push_back(vector<int> {n});
            }
        }
        else if (k > 1) {
            int iMin = start;
            int iMax = min(n, 9);
            for (int i = iMin; i <= iMax; ++i) {
                vector<vector<int>> tmp_vecs = bt (i+1, k-1, n-i);
                for (auto per_vec : tmp_vecs) {
                    per_vec.insert(per_vec.begin(), i);   
                    ans.push_back(per_vec);
                }
                // ans.insert (ans.begin(), tmp_vecs.begin(), tmp_vecs.end());
            }
        }
        return ans;
    }
};