#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();
		int** cum;
		cum = new int* [rows];
		for (int i = 0; i < rows; ++i)
			cum[i] = new int[cols];
		cum[0][0] = grid[0][0];
		for (int j = 1; j < cols; ++j)
			cum[0][j] = grid[0][j] + cum[0][j - 1];
		for (int i = 1; i < rows; ++i)
			cum[i][0] = grid[i][0] + cum[i - 1][0];

		for (int i = 1; i < rows; ++i)
			for (int j = 1; j < cols; ++j)
				cum[i][j] = grid[i][j] + (cum[i - 1][j] < cum[i][j - 1] ? cum[i - 1][j] : cum[i][j - 1]);

		return cum[rows - 1][cols - 1];
	}
};