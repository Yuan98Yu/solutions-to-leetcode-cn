#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		this->ans = 0;
		int row_size = dungeon.size();
		int col_size = dungeon[0].size();
		vector<vector<int>> dp(row_size, vector<int>(col_size));
		dp[0][0] = move(1, dungeon[0][0]);
		for (int i = 1; i < row_size; ++i)
			dp[i][0] = move(dp[i - 1][0], dungeon[i][0]);
		for (int j = 1; j < col_size; ++j) {
			dp[0][j] = move(dp[0][j - 1], dungeon[0][j]);
		}

		for (int i = 1; i < row_size; ++i) {
			for (int j = 1; j < col_size; ++j) {
				dp[i][j] = move(min(dp[i - 1][j], dp[i][j - 1]), dungeon[i][j]);
			}
		}

		return dp[row_size - 1][col_size - 1];
	}
private:
	int ans;
	int move(int cur, int room) {
		int ret = cur + room;
		return ret > 0 ? cur : 1 - room;
	}
};