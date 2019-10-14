#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<long>> cum(obstacleGrid.size(), vector<long>(obstacleGrid[0].size(), 1));
		cum[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
		for (int i = 1; i < obstacleGrid.size(); ++i) {
			if (obstacleGrid[i][0] == 1)
				cum[i][0] = 0;
			else
				cum[i][0] = cum[i - 1][0];
		}
		for (int j = 1; j < obstacleGrid[0].size(); ++j) {
			if (obstacleGrid[0][j] == 1)
				cum[0][j] = 0;
			else
				cum[0][j] = cum[0][j - 1];
		}

		for (int i = 1; i < obstacleGrid.size(); ++i)
			for (int j = 1; j < obstacleGrid[0].size(); ++j) {
				if (obstacleGrid[i][j] == 1)
					cum[i][j] = 0;
				else
					cum[i][j] = cum[i - 1][j] + cum[i][j - 1];
			}

		return cum[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};