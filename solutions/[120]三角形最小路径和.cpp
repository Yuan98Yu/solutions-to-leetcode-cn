#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> memo = triangle[triangle.size() - 1];
		for (int i = triangle.size() - 2; i >= 0; --i) {
			int tmp = memo[i + 1];
			for (int j = i; j >= 0; --j) {
				int tmp2 = memo[j];
				memo[j] = triangle[i][j] + min(tmp, memo[j]);
				tmp = tmp2;
			}
		}
		return memo[0];
	}
};