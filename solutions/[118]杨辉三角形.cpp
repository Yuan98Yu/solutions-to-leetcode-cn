#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		if (numRows == 0)
			return ans;

		ans[0] = vector<int>{ 1 };
		if (numRows > 1) {
			for (int i = 0; i < numRows - 1; ++i) {
				vector<int> tmp(i + 2);
				tmp[0] = 1;
				tmp[i + 1] = 1;
				for (int j = 1; j < ans[i].size(); ++j) {
					tmp[j] = ans[i][j] + ans[i][j - 1];
				}
				ans[i + 1] = tmp;
			}
		}

		return ans;
	}
};