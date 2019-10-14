#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;

		int left = 0, right = matrix.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == 0)
			return false;
		int row = left - 1;
		left = 0, right = matrix[0].size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (matrix[row][mid] == target)
				return true;
			else if (matrix[row][mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return false;
	}
};