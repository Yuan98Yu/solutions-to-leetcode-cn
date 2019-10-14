#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> line_is_zero(m);
		vector<bool> col_is_zero(n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					line_is_zero[i] = true;
					col_is_zero[j] = true;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			if (line_is_zero[i])
				for (int j = 0; j < n; ++j) {
					matrix[i][j] = 0;
				}
		}
		for (int j = 0; j < n; ++j) {
			if (col_is_zero[j])
				for (int i = 0; i < m; ++i) {
					matrix[i][j] = 0;
				}
		}
	}
};